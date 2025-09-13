// Cooking Stars — C++ (raylib) single-file port (Korean font + UI scaling)
// ------------------------------------------------------------
// Build (Linux/macOS):
//   g++ -std=c++17 CookingStars_raylib.cpp -o cooking_stars $(pkg-config --cflags --libs raylib)
// Build (Windows, MSYS2):
//   g++ -std=c++17 CookingStars_raylib.cpp -o cooking_stars.exe -lraylib -lgdi32 -lwinmm
// Run:
//   ./cooking_stars
// ------------------------------------------------------------
// Controls:
//   MENU: Enter=New Game, C=Controls toggle, Esc=Quit
//   GAME: WASD/Arrows move, E interact (start quest), K open cookbook
//   Quests: Space for actions; arrow keys for sequence; Platformer uses arrows/AD + Space
//   **UI size**: [-] / [+] to scale text, [0] reset
// ------------------------------------------------------------
// Notes:
// - Fixes Korean text via font autoload + DrawTextEx wrappers (DT/MT).
// - Adds runtime **UI scaling** (gUiScale) with safe font reload.
// - Includes a mini test suite (top-left badge). Tests run once on startup.

#include <raylib.h>
#include <cmath>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <cstdio>

// ------------------ Utility ------------------
static inline float clampf(float v, float a, float b){ return v < a ? a : (v > b ? b : v); }
static inline float dist2D(float x1,float y1,float x2,float y2){ float dx=x1-x2, dy=y1-y2; return std::sqrtf(dx*dx+dy*dy); }
struct Rect { float x,y,w,h; };
static inline bool AABB(const Rect &a, const Rect &b){ return a.x < b.x + b.w && a.x + a.w > b.x && a.y < b.y + b.h && a.y + a.h > b.y; }

// ------------------ Config ------------------
const int WIDTH = 960;
const int HEIGHT = 560;
const float PLAYER_SPEED = 3.5f;

// ------------------ Fonts (Korean + scaling) ------------------
static Font gFont;                 // Global UI font (Korean-capable)
static float gFontSpacing = 0.0f;  // Glyph spacing for DrawTextEx
static int   gBaseFontPx = 22;     // Base px for UI (before scaling)
static float gUiScale = 1.45f;     // Runtime UI scale ([-]/[+]/[0])
static bool  gFontIsDefault = true;

static void PushRange(std::vector<int>& cps, int a, int b){ for(int cp=a; cp<=b; ++cp) cps.push_back(cp); }

static Font LoadKoreanFontAuto(int size){
    const char* CAND[] = {
        // Local project folder (recommended)
        "NotoSansKR-Regular.ttf",
        "NotoSansKR-Regular.otf",
        "NanumGothic.ttf",
        // Common system paths (Fedora/Ubuntu variants — may differ per distro)
        "/usr/share/fonts/google-noto/NotoSansKR-Regular.otf",
        "/usr/share/fonts/noto/NotoSansKR-Regular.ttf",
        "/usr/share/fonts/nanum/NanumGothic.ttf"
    };

    std::vector<int> cps; cps.reserve(14000);
    PushRange(cps, 0x20, 0x7E);      // Basic Latin
    PushRange(cps, 0x2010, 0x2051);  // Punctuations (• etc.)
    PushRange(cps, 0x3000, 0x303F);  // CJK symbols
    PushRange(cps, 0x3130, 0x318F);  // Hangul Compatibility Jamo
    PushRange(cps, 0x1100, 0x11FF);  // Hangul Jamo
    PushRange(cps, 0xAC00, 0xD7A3);  // Hangul syllables
    PushRange(cps, 0xFF00, 0xFFEF);  // Half/Full width

    for(const char* path : CAND){
        if(FileExists(path)){
            Font f = LoadFontEx(path, size, cps.data(), (int)cps.size());
            if(f.texture.id != 0){ SetTextureFilter(f.texture, TEXTURE_FILTER_BILINEAR); return f; }
        }
    }
    return GetFontDefault();
}

static void UnloadFontSafe(){ if(!gFontIsDefault && gFont.texture.id!=0) UnloadFont(gFont); }
static int  Sc(int px){ return (int)std::round(px * gUiScale); } // scale helper
static inline int MT(const std::string &s, int size){ Vector2 m = MeasureTextEx(gFont, s.c_str(), (float)size, gFontSpacing); return (int)m.x; }
static inline void DT(const std::string &s, int x, int y, int size, Color col){ DrawTextEx(gFont, s.c_str(), {(float)x,(float)y}, (float)size, gFontSpacing, col); }

static void ReloadUIFont(){
    UnloadFontSafe();
    int px = Sc(gBaseFontPx);
    gFont = LoadKoreanFontAuto(px);
    gFontIsDefault = (gFont.texture.id==GetFontDefault().texture.id);
}

// ------------------ Game Data ------------------
enum class QuestType { MASH, SEQUENCE, BOSS, PLATFORMER };

struct QuestDef {
    QuestType type;
    std::string title;
    std::string item;
    int rewardCount = 1;
    int timeLimit = 30; // seconds, 0 for none
    // mash
    int presses = 0;
    // sequence
    int seqLen = 0;
    // boss
    int bossHP = 0;
    int playerHP = 0;
};

struct Planet {
    std::string id;
    std::string name;
    Vector2 pos;
    float r;
    Color color;
    QuestDef quest;
};

struct Recipe { std::string name; std::unordered_map<std::string,int> needs; std::string upgrade; };

// Platformer
struct Platform { float x,y,w,h; };
struct Hazard { float x,y,w,h; int type; }; // 0 lava, 1 spike
struct Powerup { float x,y,r; int type; bool active; }; // 0=double jump
struct PLevel {
    float G; std::vector<Platform> plats; std::vector<Hazard> hazards; Vector2 goal; float goalR; std::vector<Powerup> powerups;
};

// Runtime quest state
struct QuestState {
    bool open=false; bool running=false; int timeLeft=0; float accTimer=0.f;
    const Planet* planet=nullptr;
    // mash
    int presses=0;
    // sequence
    std::vector<int> seq; int idx=0;
    // boss
    float cursor=0.0f; int dir=1; int bossHP=0; int playerHP=0;
    // platformer
    bool pfOpen=false; float pfTime=40.0f; int stage=0; // 3 levels
    Rect pfr; float vxf=0, vyf=0; bool onGround=false; bool djAvail=false;
    std::vector<Powerup> pfPowerups;
};

// Test report
struct TestCase { std::string name; bool pass; std::string msg; };
struct TestReport { bool allPass; std::vector<TestCase> results; };

// ------------------ Globals ------------------
static std::vector<Vector2> gStars;
static std::vector<Planet> gPlanets;
static std::vector<Recipe> gRecipes;
static std::vector<PLevel> gLevels; // platformer levels
static std::unordered_map<std::string,int> gInventory;
static std::vector<std::string> gUpgrades;

// UI state
enum class Screen { MENU, GAME };
static Screen gScreen = Screen::MENU;
static bool gShowControls = true; // default open to show bigger text immediately
static TestReport gTests;

// Quest state
static QuestState gQ;

// ------------------ Helpers ------------------
static void AddInventory(const std::string& item, int n){ gInventory[item] += n; }
static bool HasNeeds(const std::unordered_map<std::string,int>& needs){
    for (auto &kv : needs){ auto it=gInventory.find(kv.first); if(it==gInventory.end()||it->second<kv.second) return false; }
    return true;
}
static void ConsumeNeeds(const std::unordered_map<std::string,int>& needs){
    for (auto &kv : needs){ gInventory[kv.first]-=kv.second; if(gInventory[kv.first]<=0) gInventory.erase(kv.first);} }
static bool Contains(const std::vector<std::string>& v, const std::string& s){ return std::find(v.begin(),v.end(),s)!=v.end(); }

// ------------------ Test Suite ------------------
static TestReport RunTests(){
    TestReport rep; rep.allPass=true;
    auto T=[&](const std::string& name, bool pass, const std::string& msg=""){
        rep.results.push_back({name,pass,msg}); if(!pass) rep.allPass=false; };
    // math
    T("clamp upper", clampf(5,0,3)==3);
    T("clamp lower", clampf(-2,0,3)==0);
    T("dist 3-4-5", (int)std::round(dist2D(0,0,3,4))==5);
    // AABB
    Rect a{0,0,10,10}, b{5,5,3,3}, c{20,20,2,2};
    T("aabb overlap", AABB(a,b)==true);
    T("aabb no overlap", AABB(a,c)==false);
    // UI scale math sanity
    T("scale 2x of 10 -> 20", (int)std::round(10*2.0f)==20);
    return rep;
}

static void AppendDataTests(TestReport &rep){
    auto T=[&](const std::string& name, bool pass, const std::string& msg=""){ rep.results.push_back({name,pass,msg}); if(!pass) rep.allPass=false; };
    // recipes validity
    bool recipesOk = true; for(auto &r: gRecipes){ if(r.name.empty()||r.needs.empty()) recipesOk=false; }
    T("recipes valid", recipesOk);
    // planets have quests
    bool planetsOk = true; for(auto &p: gPlanets){ if(p.quest.title.empty()) planetsOk=false; }
    T("planets have quests", planetsOk);
}

static void AppendFontTests(TestReport &rep){
    auto T=[&](const std::string& name, bool pass, const std::string& msg=""){ rep.results.push_back({name,pass,msg}); if(!pass) rep.allPass=false; };
    T("font loaded", gFont.texture.id != 0);
    T("glyph U+AC00", GetGlyphIndex(gFont, 0xAC00) >= 0);
    T("glyph U+D55C", GetGlyphIndex(gFont, 0xD55C) >= 0);
    T("glyph bullet", GetGlyphIndex(gFont, 0x2022) >= 0);
}

// ------------------ Data Init ------------------
static void InitStars(int n=180){
    gStars.clear(); gStars.reserve(n);
    for(int i=0;i<n;i++){ gStars.push_back({ (float)GetRandomValue(0,WIDTH), (float)GetRandomValue(0,HEIGHT) }); }
}

static void InitPlanets(){
    gPlanets.clear();
    gPlanets.push_back({"volcano","Spicy Planet",{180,120},34, (Color){255,89,43,255}, {QuestType::MASH, "불꽃 향신료 수확", "Fire Spice", 1, 30, 12}});
    gPlanets.push_back({"ice","Frozen Planet",{740,140},32, (Color){91,198,255,255}, {QuestType::SEQUENCE, "빙하 아이스버섯 퍼즐", "Ice Shroom", 1, 25, 0, 5}});
    gPlanets.push_back({"forest","Forest Planet",{230,420},36, (Color){42,214,123,255}, {QuestType::MASH, "루미나 버섯 채집", "Lumina Cap", 1, 0, 14}});
    gPlanets.push_back({"aqua","Aqua Planet",{760,420},40, (Color){111,124,255,255}, {QuestType::BOSS, "심해 채집(보스전)", "Abyssal Meat", 1, 30, 0, 0, 6, 3}});
    gPlanets.push_back({"arcade","Arcade Satellite",{480,80},28, (Color){184,108,255,255}, {QuestType::PLATFORMER, "스타 페어 수확(플랫포머)", "Star Berry", 1, 40}});
}

static void InitRecipes(){
    gRecipes.clear();
    gRecipes.push_back({"지옥 라면 (Hell Ramen)", {{"Fire Spice",3}}, "방열 장치 업그레이드"});
    gRecipes.push_back({"눈꽃 샤베트 (Snowflake Sherbet)", {{"Ice Shroom",2}}, "냉각 장치 업그레이드"});
    gRecipes.push_back({"버섯 리조또 (Mushroom Risotto)", {{"Lumina Cap",2}}, "추진력 향상 모듈"});
    gRecipes.push_back({"은하 해물탕 (Galactic Seafood Stew)", {{"Abyssal Meat",1},{"Ice Shroom",1}}, "수중 항해 모드"});
    gRecipes.push_back({"코멧 파르페 (Comet Parfait)", {{"Star Berry",1},{"Ice Shroom",1}}, "관성 안정 제어기"});
}

static void InitPlatformerLevels(){
    gLevels.clear();
    // Level 1
    {
        PLevel L; L.G=1800; L.goal={505,95}; L.goalR=10;
        L.plats = {{0,300,560,20},{110,240,90,12},{230,200,90,12},{350,160,90,12},{460,120,80,12}};
        L.hazards = {{0,316,560,4,0}}; // lava line
        L.powerups = {};
        gLevels.push_back(L);
    }
    // Level 2 (low gravity, spikes)
    {
        PLevel L; L.G=1000; L.goal={505,175}; L.goalR=10;
        L.plats = {{0,300,560,20},{140,250,80,12},{280,220,80,12},{420,200,90,12}};
        L.hazards = {{200,300,60,16,1},{330,300,60,16,1}};
        L.powerups = {};
        gLevels.push_back(L);
    }
    // Level 3 (high gravity + double jump orb)
    {
        PLevel L; L.G=2400; L.goal={505,160}; L.goalR=10;
        L.plats = {{0,300,560,20},{160,260,70,12},{300,215,70,12},{420,185,70,12}};
        L.hazards = {{240,300,40,16,1},{360,300,40,16,1}};
        L.powerups = {{250,235,6,0,true}}; // double jump orb
        gLevels.push_back(L);
    }
}

// ------------------ Drawing Helpers ------------------
static void DrawStarfield(){ for(auto &s: gStars) DrawPixelV(s, WHITE); }

static void DrawPlanet(const Planet &p){
    DrawCircleV(p.pos, p.r, p.color);
    int tw = MT(p.name, Sc(12));
    DT(p.name, (int)(p.pos.x - tw/2), (int)(p.pos.y - p.r - Sc(16)), Sc(12), Color{220,220,235,200});
}

static void DrawHUD(const std::string &hint){
    // right panel
    int x = WIDTH-Sc(300), y=Sc(10), w=Sc(290), h=Sc(220);
    DrawRectangleRounded({(float)x,(float)y,(float)w,(float)h}, 0.1f, 8, Color{255,255,255,35});
    DrawRectangleLinesEx({(float)x,(float)y,(float)w,(float)h},1, Color{255,255,255,40});
    DT("기지 패널", x+Sc(10), y+Sc(8), Sc(18), RAYWHITE);
    // inventory
    int iy = y+Sc(36);
    if(gInventory.empty()) DT("인벤토리 비어있음", x+Sc(10), iy, Sc(14), Color{220,220,220,200});
    else{
        for(auto &kv : gInventory){
            std::string s = kv.first + " x" + std::to_string(kv.second);
            DT(s, x+Sc(10), iy, Sc(14), Color{220,220,220,220});
            iy += Sc(18);
        }
    }
    DT("[K] 요리책", x+Sc(10), y+h-Sc(20), Sc(14), Color{200,240,255,220});

    // hint bottom
    int hx=Sc(10), hy=HEIGHT-Sc(40), hw=WIDTH-Sc(20), hh=Sc(28);
    DrawRectangleRounded({(float)hx,(float)hy,(float)hw,(float)hh}, 0.1f, 8, Color{255,255,255,35});
    DT(hint, hx+Sc(10), hy+Sc(5), Sc(14), RAYWHITE);
}

static void DrawMinimap(Vector2 player){
    int x=Sc(10),y=Sc(10),w=Sc(150),h=Sc(150); DrawRectangleRounded({(float)x,(float)y,(float)w,(float)h},0.15f,8,Color{255,255,255,35});
    for(auto &p: gPlanets){ int px=x+Sc(10) + (int)((p.pos.x/WIDTH)*(w-Sc(20))); int py=y+Sc(10) + (int)((p.pos.y/HEIGHT)*(h-Sc(20))); DrawCircle(px,py,3,p.color); }
    int ux=x+Sc(10) + (int)((player.x/WIDTH)*(w-Sc(20))); int uy=y+Sc(10) + (int)((player.y/HEIGHT)*(h-Sc(20))); DrawCircle(ux,uy,3,WHITE);
}

// ------------------ Quest Logic ------------------
static void OpenQuest(const Planet* P){
    gQ = QuestState{}; gQ.open=true; gQ.running=false; gQ.planet=P; gQ.timeLeft=P->quest.timeLimit; gQ.accTimer=0.f;
    if(P->quest.type==QuestType::SEQUENCE){ gQ.seq.clear(); for(int i=0;i<(P->quest.seqLen>0?P->quest.seqLen:5); ++i){ int k = GetRandomValue(0,3); gQ.seq.push_back(k);} gQ.idx=0; }
    if(P->quest.type==QuestType::BOSS){ gQ.cursor=0.f; gQ.dir=1; gQ.bossHP=P->quest.bossHP; gQ.playerHP=P->quest.playerHP; }
    if(P->quest.type==QuestType::PLATFORMER){ gQ.pfOpen=false; gQ.pfTime=(float)P->quest.timeLimit; gQ.stage=0; gQ.pfr={40,260,16,24}; gQ.vxf=0; gQ.vyf=0; gQ.onGround=false; gQ.djAvail=false; gQ.pfPowerups=gLevels[0].powerups; }
}

static void GrantReward(){ AddInventory(gQ.planet->quest.item, gQ.planet->quest.rewardCount); gQ.open=false; gQ.running=false; }
static void FailQuest(){ gQ.open=false; gQ.running=false; }

static void DrawQuestPanel(const char* line1, const char* line2=nullptr){
    int w=Sc(620),h=Sc(360); int x=(WIDTH-w)/2; int y=(HEIGHT-h)/2;
    DrawRectangle(x-Sc(6),y-Sc(6),w+Sc(12),h+Sc(12), Color{0,0,0,140});
    DrawRectangleRounded({(float)x,(float)y,(float)w,(float)h},0.06f,10, Color{18,26,48,220});
    DT(line1, x+Sc(18), y+Sc(16), Sc(22), RAYWHITE);
    if(line2) DT(line2, x+Sc(18), y+Sc(42), Sc(16), Color{200,220,240,220});
}

static void DrawBossTrack(float cursor){
    int w=Sc(520), h=Sc(16); int x=WIDTH/2-w/2, y=HEIGHT/2+Sc(60);
    DrawRectangleRounded({(float)x,(float)y,(float)w,(float)h},0.4f,8, Color{255,255,255,30});
    int zw = (int)(w*0.18f); // success window 18%
    DrawRectangle(x + w/2 - zw/2, y, zw, h, Color{255,255,255,64});
    int cx = x + (int)(cursor*w);
    DrawRectangle(cx-Sc(3),y,Sc(6),h, Color{255,255,255,220});
}

static void UpdateBoss(float dt){
    float c=gQ.cursor + gQ.dir * dt * 1.2f; int d=gQ.dir; if(c>1){c=1; d=-1;} if(c<0){c=0; d=1;} gQ.cursor=c; gQ.dir=d;
    if (IsKeyPressed(KEY_SPACE) && gQ.running){
        float zone=0.18f; bool hit = std::fabs(gQ.cursor-0.5f) <= zone*0.5f;
        if(hit) gQ.bossHP = std::max(0, gQ.bossHP-1); else gQ.playerHP = std::max(0, gQ.playerHP-1);
    }
    if(gQ.bossHP<=0){ GrantReward(); }
    if(gQ.playerHP<=0){ FailQuest(); }
}

static void UpdateMash(float /*dt*/){ if(IsKeyPressed(KEY_SPACE) && gQ.running){ gQ.presses = std::min(gQ.presses+1, gQ.planet->quest.presses); } if(gQ.presses>=gQ.planet->quest.presses){ GrantReward(); } }

static void UpdateSequence(float /*dt*/){
    if(!gQ.running) return;
    auto need = gQ.seq[gQ.idx]; int press=-1;
    if(IsKeyPressed(KEY_UP)) press=0; else if(IsKeyPressed(KEY_DOWN)) press=1; else if(IsKeyPressed(KEY_LEFT)) press=2; else if(IsKeyPressed(KEY_RIGHT)) press=3;
    if(press!=-1){ if(press==need) gQ.idx++; else gQ.idx = std::max(0, gQ.idx-1); }
    if(gQ.idx >= (int)gQ.seq.size()) GrantReward();
}

// Platformer helpers
static void PF_ResetStage(int s){ gQ.stage=s; gQ.pfr={40,260,16,24}; gQ.vxf=0; gQ.vyf=0; gQ.onGround=false; gQ.djAvail=false; gQ.pfPowerups=gLevels[s].powerups; }

static void PF_Update(float dt){
    if(!gQ.running || !gQ.pfOpen) return; int s=gQ.stage; if(s<0||s>=(int)gLevels.size()) return; const PLevel &L = gLevels[s];
    // input
    float ax=0; if(IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) ax-=500; if(IsKeyDown(KEY_RIGHT)||IsKeyDown(KEY_D)) ax+=500; gQ.vxf = clampf(gQ.vxf + ax*dt, -220, 220); gQ.vyf += L.G*dt;
    bool pressed = IsKeyDown(KEY_SPACE); static bool prevPressed=false; bool jumpEdge = pressed && !prevPressed; prevPressed = pressed;

    if(jumpEdge){ if(gQ.onGround){ gQ.vyf = -620; gQ.onGround=false; } else if(gQ.djAvail){ gQ.vyf = -620; gQ.djAvail=false; } }

    float nx = gQ.pfr.x + gQ.vxf*dt; float ny = gQ.pfr.y + gQ.vyf*dt; gQ.onGround=false;
    // vertical sweep vs platforms
    for(const auto &pl: L.plats){
        bool overlapX = (nx + gQ.pfr.w > pl.x) && (nx < pl.x + pl.w);
        float prevBottom = gQ.pfr.y + gQ.pfr.h; float nextBottom = ny + gQ.pfr.h;
        float prevTop = gQ.pfr.y; float nextTop = ny;
        if(gQ.vyf>0 && overlapX && prevBottom<=pl.y && nextBottom>=pl.y){ ny = pl.y - gQ.pfr.h; gQ.vyf=0; gQ.onGround=true; }
        if(gQ.vyf<0 && overlapX && prevTop>=pl.y+pl.h && nextTop<=pl.y+pl.h){ ny = pl.y + pl.h; gQ.vyf=0; }
    }
    // horizontal resolution
    Rect cand{nx,ny,gQ.pfr.w,gQ.pfr.h};
    for(const auto &pl: L.plats){ Rect r{pl.x,pl.y,pl.w,pl.h}; if(AABB(cand,r)){ if(gQ.vxf>0 && gQ.pfr.x+gQ.pfr.w<=pl.x) nx = pl.x - gQ.pfr.w; else if(gQ.vxf<0 && gQ.pfr.x>=pl.x+pl.w) nx = pl.x + pl.w; gQ.vxf *= -0.2f; cand.x=nx; }}

    // bounds & hazards
    nx = clampf(nx, 0, 560 - gQ.pfr.w); if(ny > 320+100){ FailQuest(); return; } ny = std::min(ny, 320 - gQ.pfr.h);
    for(const auto &hz: L.hazards){ Rect r{hz.x,hz.y,hz.w,hz.h}; if(AABB({nx,ny,gQ.pfr.w,gQ.pfr.h},r)){ FailQuest(); return; } }

    // powerups
    for(auto &pu : gQ.pfPowerups){ if(!pu.active) continue; Rect pr{pu.x-pu.r, pu.y-pu.r, pu.r*2, pu.r*2}; if(AABB({nx,ny,gQ.pfr.w,gQ.pfr.h}, pr)){ if(pu.type==0) gQ.djAvail=true; pu.active=false; } }

    // goal
    if(dist2D(nx+gQ.pfr.w*0.5f, ny+gQ.pfr.h*0.5f, L.goal.x, L.goal.y) <= L.goalR + 10){ if(gQ.stage < (int)gLevels.size()-1){ PF_ResetStage(gQ.stage+1); } else { GrantReward(); return; } }

    gQ.pfr.x = nx; gQ.pfr.y = ny; if(gQ.onGround) gQ.vxf *= 0.86f;

    // timer
    gQ.pfTime = std::max(0.0f, gQ.pfTime - dt); if(gQ.pfTime<=0){ FailQuest(); }
}

static void DrawPlatformer(){
    int w=Sc(580),h=Sc(360); int x=WIDTH/2-w/2, y=HEIGHT/2-h/2+Sc(20);
    DrawRectangleRounded({(float)x,(float)y,(float)w,(float)h},0.06f,8, Color{10,17,48,220});
    const PLevel &L = gLevels[gQ.stage];
    // plats
    for(const auto &pl: L.plats) DrawRectangle(x+(int)pl.x, y+(int)pl.y, (int)pl.w,(int)pl.h, Color{255,255,255,40});
    // hazards
    for(const auto &hz: L.hazards){ Color c = hz.type==0 ? Color{220,60,40,160} : Color{220,70,70,180}; DrawRectangle(x+(int)hz.x, y+(int)hz.y, (int)hz.w,(int)hz.h, c); }
    // powerups
    for(const auto &pu: gQ.pfPowerups){ if(!pu.active) continue; DrawCircle(x+(int)pu.x, y+(int)pu.y, pu.r, Color{80,220,255,220}); }
    // goal
    DrawCircle(x+(int)L.goal.x, y+(int)L.goal.y, L.goalR, Color{255,191,64,220});
    // player
    DrawRectangle(x+(int)gQ.pfr.x, y+(int)gQ.pfr.y, (int)gQ.pfr.w,(int)gQ.pfr.h, WHITE);
    // header
    char buf[128]; std::snprintf(buf,sizeof(buf),"Level %d/%d  •  남은 시간 %.1fs", gQ.stage+1,(int)gLevels.size(), gQ.pfTime);
    DT(buf, x, y-Sc(22), Sc(16), RAYWHITE);
}

// ------------------ Main ------------------
int main(){
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(WIDTH, HEIGHT, "Cooking Stars — C++ raylib");
    SetTargetFPS(60);

    // Initial font load with scaling
    ReloadUIFont();

    // Init data & tests
    InitStars(); InitPlanets(); InitRecipes(); InitPlatformerLevels();
    gTests = RunTests(); AppendDataTests(gTests); AppendFontTests(gTests);

    Vector2 player = {(float)WIDTH/2,(float)HEIGHT/2};
    std::string hint = "행성에 가까이 가서 [E]로 상호작용. WASD/화살표 이동.";

    while(!WindowShouldClose()){
        float dt = GetFrameTime();
        // UI scale hotkeys
        if(IsKeyPressed(KEY_EQUAL) || IsKeyPressed(KEY_KP_ADD)) { gUiScale = clampf(gUiScale+0.1f, 0.9f, 2.8f); ReloadUIFont(); }
        if(IsKeyPressed(KEY_MINUS) || IsKeyPressed(KEY_KP_SUBTRACT)) { gUiScale = clampf(gUiScale-0.1f, 0.9f, 2.8f); ReloadUIFont(); }
        if(IsKeyPressed(KEY_ZERO)) { gUiScale = 1.45f; ReloadUIFont(); }

        BeginDrawing(); ClearBackground(Color{8,12,20,255});
        DrawStarfield();

        // dev badge
        {
            Color bg = gTests.allPass ? Color{36,197,110,60} : Color{255,90,90,60};
            DrawRectangle(Sc(8),Sc(8), Sc(230), Sc(28), bg); // background rectangle (draw again below for color)
            DrawRectangle(Sc(8),Sc(8), Sc(230), Sc(28), bg);
            int passc=0; for(auto &r:gTests.results) if(r.pass) passc++; char tb[128];
            std::snprintf(tb,sizeof(tb),"Tests: %d/%d %s", passc,(int)gTests.results.size(), gTests.allPass?"PASS":"FAIL");
            DT(tb, Sc(12), Sc(12), Sc(14), RAYWHITE);
        }

        if(gScreen==Screen::MENU){
            DT("COOKING STARS", WIDTH/2 - MT("COOKING STARS", Sc(46))/2, HEIGHT/2-Sc(90), Sc(46), RAYWHITE);
            DT("Enter=새 게임   C=컨트롤   Esc=종료   [+/-] 글자크기", WIDTH/2-Sc(320), HEIGHT/2-Sc(22), Sc(18), Color{220,220,235,230});
            if(gShowControls){ DrawQuestPanel("컨트롤","이동: WASD/화살표  •  상호작용: E  •  점프/액션: Space  •  [+/-] 글자크기"); }
            if(IsKeyPressed(KEY_C)) gShowControls=!gShowControls;
            if(IsKeyPressed(KEY_ENTER)){ gScreen=Screen::GAME; }
        }
        else if(gScreen==Screen::GAME){
            // movement
            int dx = (IsKeyDown(KEY_RIGHT)||IsKeyDown(KEY_D)) - (IsKeyDown(KEY_LEFT)||IsKeyDown(KEY_A));
            int dy = (IsKeyDown(KEY_DOWN)||IsKeyDown(KEY_S)) - (IsKeyDown(KEY_UP)||IsKeyDown(KEY_W));
            if(dx||dy){ float m=std::sqrtf((float)(dx*dx+dy*dy)); player.x = clampf(player.x + (dx/m)*PLAYER_SPEED, 12, WIDTH-12); player.y=clampf(player.y + (dy/m)*PLAYER_SPEED, 12, HEIGHT-12); }

            // draw planets
            for(auto &p: gPlanets) DrawPlanet(p);
            // player
            DrawCircleV(player, 6, RAYWHITE); DT("YOU", (int)player.x-Sc(10), (int)player.y-Sc(18), Sc(12), Color{230,230,255,210});
            DrawMinimap(player);

            // interact E
            if(IsKeyPressed(KEY_E) && !gQ.open){ for(auto &p: gPlanets){ if(dist2D(player.x,player.y,p.pos.x,p.pos.y) < p.r + 26){ OpenQuest(&p); break; } } }

            // HUD
            DrawHUD(hint);

            // Cookbook
            static bool cookbook=false; static int cookIdx=-1; static bool cookOpen=false; static float cookX=0, cookV=0, cookStable=0, cookTime=20; const float cookBand=0.3f;
            if(IsKeyPressed(KEY_K) && !gQ.open){ cookbook = !cookbook; }
            if(cookbook){
                DrawQuestPanel("요리책","재료가 충분한 레시피만 조리 가능. [1..5] 선택, Space 조리 시작, K 닫기");
                int y=HEIGHT/2-Sc(100); for(int i=0;i<(int)gRecipes.size();++i){ char line[256]; bool ok=HasNeeds(gRecipes[i].needs); std::snprintf(line,sizeof(line),"%d) %s %s", i+1, gRecipes[i].name.c_str(), ok?"":"(재료부족)"); DT(line, WIDTH/2-Sc(300), y+Sc(60)+i*Sc(20), Sc(14), ok?RAYWHITE:Color{180,180,180,200}); }
                for(int i=0;i<(int)gRecipes.size() && i<9;i++){ if(IsKeyPressed((KeyboardKey)(KEY_ONE+i))) cookIdx=i; }
                if(cookIdx>=0 && cookIdx<(int)gRecipes.size() && HasNeeds(gRecipes[cookIdx].needs) && IsKeyPressed(KEY_SPACE)){
                    cookOpen=true; cookX=0; cookV=0; cookStable=0; cookTime=20; cookbook=false;
                }
            }
            if(cookOpen){
                DrawQuestPanel("저중력 조리","슬라이더를 중앙 안전 구역에 5초 연속 유지 — ←/→ 미세 제어");
                // physics
                float a=0; if(IsKeyDown(KEY_LEFT)) a-=1.8f; if(IsKeyDown(KEY_RIGHT)) a+=1.8f; cookV = cookV*0.985f + a*dt; cookX = clampf(cookX + (cookV + a*dt)*dt, -1, 1); if(std::fabs(cookX)<=cookBand) cookStable+=dt; else cookStable=0; cookTime=std::max(0.0f, cookTime-dt);
                // bar
                int w=Sc(520), h=Sc(14); int x=WIDTH/2-w/2, y=HEIGHT/2+Sc(60); DrawRectangleRounded({(float)x,(float)y,(float)w,(float)h},0.4f,8, Color{255,255,255,30}); int bandW=(int)(w*cookBand*2); DrawRectangle(x+w/2-bandW/2,y,bandW,h, Color{0,255,180,80}); int cx=x+(int)(((cookX+1)/2.0f)*w); DrawRectangle(cx-Sc(3),y,Sc(6),h, RAYWHITE);
                char info[128]; std::snprintf(info,sizeof(info),"안정도 %.1fs / 5.0s   남은 %.1fs", cookStable, cookTime); DT(info, x, y-Sc(18), Sc(16), RAYWHITE);
                if(cookStable>=5){ ConsumeNeeds(gRecipes[cookIdx].needs); if(!gRecipes[cookIdx].upgrade.empty() && !Contains(gUpgrades,gRecipes[cookIdx].upgrade)) gUpgrades.push_back(gRecipes[cookIdx].upgrade); cookOpen=false; }
                else if(cookTime<=0){ cookOpen=false; }
            }

            // Quest overlay
            if(gQ.open){
                const QuestDef &q = gQ.planet->quest; std::string subtitle = gQ.planet->name + std::string(" — Space 시작/진행");
                DrawQuestPanel(q.title.c_str(), subtitle.c_str());
                // footer-like info
                char info[128]; if(q.timeLimit>0){ std::snprintf(info,sizeof(info),"남은 시간: %d s", gQ.timeLeft); DT(info, WIDTH/2-Sc(300), HEIGHT/2+Sc(140), Sc(16), RAYWHITE);}            
                if(!gQ.running){ if(IsKeyPressed(KEY_SPACE)){ gQ.running=true; if(q.type==QuestType::PLATFORMER) gQ.pfOpen=true; } }
                else{
                    // timer
                    if(q.timeLimit>0){ gQ.accTimer += dt; if(gQ.accTimer>=1.0f){ gQ.accTimer-=1.0f; gQ.timeLeft = std::max(0, gQ.timeLeft-1); if(gQ.timeLeft==0){ if(q.type!=QuestType::PLATFORMER) FailQuest(); } } }
                    // type-specific
                    if(q.type==QuestType::MASH){ DT("Space 연타로 게이지 채우기", WIDTH/2-Sc(300), HEIGHT/2+Sc(90), Sc(16), Color{200,220,240,220}); DrawRectangle(WIDTH/2-Sc(220), HEIGHT/2+Sc(112), Sc(440), Sc(10), Color{255,255,255,40}); int w=(int)(Sc(440) * (float)gQ.presses / (float)std::max(1,q.presses)); DrawRectangle(WIDTH/2-Sc(220), HEIGHT/2+Sc(112), w, Sc(10), Color{0,255,150,120}); }
                    if(q.type==QuestType::SEQUENCE){ DT("표시된 화살표 순서를 입력", WIDTH/2-Sc(300), HEIGHT/2+Sc(90), Sc(16), Color{200,220,240,220}); int sx=WIDTH/2-Sc(220), sy=HEIGHT/2+Sc(116); for(int i=0;i<(int)gQ.seq.size();++i){ char c; int k=gQ.seq[i]; c = (k==0?'^': k==1?'v': k==2?'<':'>'); char t[4] = {c,0,0,0}; Color col = i<gQ.idx? Color{0,255,180,200} : Color{255,255,255,120}; DT(t, sx+i*Sc(22), sy, Sc(18), col);} }
                    if(q.type==QuestType::BOSS){ DT("커서가 중앙 영역에 올 때 Space!", WIDTH/2-Sc(300), HEIGHT/2+Sc(90), Sc(16), Color{200,220,240,220}); DrawBossTrack(gQ.cursor); char hp[128]; std::snprintf(hp,sizeof(hp),"Boss %d  •  Player %d", gQ.bossHP, gQ.playerHP); DT(hp, WIDTH/2-Sc(60), HEIGHT/2+Sc(100), Sc(16), RAYWHITE); UpdateBoss(dt); }
                    if(q.type==QuestType::PLATFORMER){ DT("골드 스타 도달 — Space 점프", WIDTH/2-Sc(300), HEIGHT/2+Sc(90), Sc(16), Color{200,220,240,220}); DrawPlatformer(); PF_Update(dt); }
                }
                if(IsKeyPressed(KEY_ESCAPE)){ gQ.open=false; gQ.running=false; }
            }
        }

        EndDrawing();
    }

    UnloadFontSafe();
    CloseWindow();
    return 0;
}
