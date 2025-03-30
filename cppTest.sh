#!/bin/bash
set -euo pipefail
export LC_ALL=ko_KR.UTF-8

# 필수 명령어 설치 여부 확인
for cmd in dialog g++ lcov genhtml xdg-open; do
    if ! command -v "$cmd" &>/dev/null; then
        echo "Error: $cmd 명령어를 찾을 수 없습니다. 설치 후 다시 시도하세요."
        exit 1
    fi
done

# ------------------------------------------------------------------------------
# 1) dialog로 C++ 소스 선택
# ------------------------------------------------------------------------------
selected_file=$(dialog --title "C++ 파일 선택" --fselect "$HOME/Documents/problems/" 24 68 2>&1 1>/dev/tty)
ret=$?
clear # dialog 종료, 터미널 화면 복구

if [ $ret -ne 0 ] || [ -z "$selected_file" ]; then
    dialog --msgbox "선택된 파일이 없습니다. 종료합니다." 7 50
    clear
    exit 1
fi

# 선택한 파일의 폴더로 이동
parent_folder=$(dirname "$selected_file")
pushd "$parent_folder" >/dev/null

source_file=$(basename "$selected_file")

# if selected_file name is main.cpp, then skip copy
if [ "$source_file" == "main.cpp" ]; then
    dialog --msgbox "main.cpp 파일을 선택했습니다. 복사하지 않고 진행합니다." 7 50
    clear
else
    cp "$selected_file" main.cpp
    dialog --msgbox "성공적으로 ${source_file}를 main.cpp로 복사했습니다." 7 50
    clear
fi

# ------------------------------------------------------------------------------
# 2) 커버리지 측정 및 리포트 생성 함수
# ------------------------------------------------------------------------------
run_coverage() {
    local src="$1"

    dialog --infobox "[$(date +"%T")] ${src} 컴파일 중..." 5 50
    sleep 2
    clear # dialog 종료

    # 컴파일 (Coverage 옵션 포함)
    g++ -std=c++2c -g -O0 -fprofile-arcs -ftest-coverage -Wall \
        -lboost_system -lboost_thread -pthread -ltbb \
        -o main "$src"

    # 커버리지 카운터 초기화
    lcov --directory . --zerocounters

    # 초기 베이스라인 수집
    lcov --ignore-errors empty --capture --initial --directory . --output-file coverage_before.info

    # ----------------------------------------------------------------------------
    # 3) dialog 완전히 종료 후 프로그램 실행
    #    - 여기서부터는 표준 입력/출력이 `./main`과 충돌 없이 동작
    # ----------------------------------------------------------------------------
    echo "[$(date +"%T")] 프로그램을 실행합니다."
    sleep 1
    ./main

    echo "계속 진행하시려면 아무 키나 누르십시오."
    read -r -n 1 -s

    # ----------------------------------------------------------------------------
    # 4) 실행이 끝나면 다시 커버리지 수집 & dialog 사용
    # ----------------------------------------------------------------------------
    lcov --ignore-errors inconsistent,inconsistent --capture --directory . \
        --output-file coverage_after.info
    lcov -a coverage_before.info -a coverage_after.info --output-file coverage_diff.info

    lcov --list coverage_before.info >/tmp/coverage_before.txt
    dialog --title "커버리지 결과 (Before)" --textbox /tmp/coverage_before.txt 20 70
    rm /tmp/coverage_before.txt
    clear

    lcov --ignore-errors inconsistent,inconsistent \
        --list coverage_after.info >/tmp/coverage_after.txt
    dialog --title "커버리지 결과 (After)" --textbox /tmp/coverage_after.txt 20 70
    rm /tmp/coverage_after.txt
    clear

    lcov --list coverage_diff.info >/tmp/coverage_diff.txt
    dialog --title "커버리지 결과 (Diff)" --textbox /tmp/coverage_diff.txt 20 70
    rm /tmp/coverage_diff.txt
    clear

    dialog --infobox "[$(date +"%T")] HTML 리포트 생성 중..." 5 50
    sleep 1
    genhtml --ignore-errors inconsistent,inconsistent coverage_diff.info \
        --output-directory out_diff --css="../custom.css" >/dev/null

    dialog --msgbox "HTML 리포트가 성공적으로 생성되었습니다.\n폴더: out_diff" 7 60
    clear
}

# ------------------------------------------------------------------------------
# 커버리지 실행
# ------------------------------------------------------------------------------
run_coverage "main.cpp"

popd >/dev/null
clear
echo "모든 작업이 완료되었습니다."
