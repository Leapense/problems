#!/bin/bash
set -euo pipefail
export LC_ALL=ko_KR.UTF-8

# 필수 명령어 설치 여부 확인
for cmd in dialog python3 coverage xdg-open; do
    if ! command -v "$cmd" &> /dev/null; then
        echo "Error: $cmd 명령어를 찾을 수 없습니다. 설치 후 다시 시도하세요."
        exit 1
    fi
done

# ------------------------------------------------------------------------------
# 1) dialog로 Python 파일 선택
# ------------------------------------------------------------------------------
selected_file=$(dialog --title "Python 파일 선택" --fselect "$HOME/Documents/problems/" 24 68 2>&1 1>/dev/tty)
ret=$?
clear  # dialog 종료, 터미널 화면 복구

if [ $ret -ne 0 ] || [ -z "$selected_file" ]; then
    dialog --msgbox "선택된 파일이 없습니다. 종료합니다." 7 50
    clear
    exit 1
fi

# 선택한 파일의 폴더로 이동
parent_folder=$(dirname "$selected_file")
pushd "$parent_folder" > /dev/null

source_file=$(basename "$selected_file")
cp "$selected_file" main.py

dialog --msgbox "성공적으로 ${source_file}를 main.py로 복사했습니다." 7 50
clear

# ------------------------------------------------------------------------------
# 2) 커버리지 측정 및 리포트 생성 함수
# ------------------------------------------------------------------------------
run_coverage() {
    local src="$1"

    dialog --infobox "[$(date +"%T")] ${src} 실행 중..." 5 50
    sleep 2
    clear  # dialog 종료

    # 이전 커버리지 데이터 삭제
    coverage erase

    # Python 스크립트를 커버리지 측정과 함께 실행
    coverage run "$src"

    echo "[$(date +"%T")] 프로그램 실행 완료."
    echo "프로그램 실행이 완료되었습니다."
    echo "계속 진행하시려면 아무 키나 누르십시오."
    read -r -n 1 -s
    clear

    # 터미널에 커버리지 리포트 출력
    coverage report > /tmp/coverage_report.txt
    dialog --title "커버리지 결과 (Report)" --textbox /tmp/coverage_report.txt 20 70
    rm /tmp/coverage_report.txt
    clear

    dialog --infobox "[$(date +"%T")] HTML 리포트 생성 중..." 5 50
    sleep 1
    coverage html
    clear

    dialog --msgbox "HTML 리포트가 성공적으로 생성되었습니다.\n폴더: htmlcov" 7 60
    clear

    # HTML 리포트를 기본 브라우저로 열기 (xdg-open은 Linux에서 사용)
    xdg-open htmlcov/index.html &> /dev/null || true
}

# ------------------------------------------------------------------------------
# 커버리지 실행
# ------------------------------------------------------------------------------
run_coverage "main.py"

popd > /dev/null
clear
echo "모든 작업이 완료되었습니다."
