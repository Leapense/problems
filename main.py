import gc
import os
import platform
import subprocess
import psutil # 메모리 사용량 측정을 위해 import

def get_current_memory_usage():
    """현재 파이썬 프로세스의 메모리 사용량(MB 단위)을 반환합니다."""
    process = psutil.Process(os.getpid())
    mem_info = process.memory_info()
    # RSS (Resident Set Size)는 실제 물리 메모리 사용량을 나타냅니다.
    return mem_info.rss / (1024 * 1024)

def clear_python_memory():
    """
    파이썬 인터프리터 내의 가비지 컬렉션을 수행하고,
    gc.collect() 전후의 메모리 사용량 변화를 측정하여 출력합니다.
    """
    print("\n--- Python Memory Cleanup ---")
    print("Attempting to collect garbage in Python interpreter...")

    # gc.collect() 호출 전 메모리 사용량
    mem_before_gc = get_current_memory_usage()
    print(f"Memory usage before gc.collect(): {mem_before_gc:.2f} MB")

    # 가비지 컬렉션 실행
    # gc.collect()는 수집된 도달 불가능한 객체의 수를 반환합니다.
    collected_objects_count = gc.collect()
    print(f"gc.collect() processed. Number of unreachable objects collected: {collected_objects_count}")

    # gc.collect() 호출 후 메모리 사용량
    mem_after_gc = get_current_memory_usage()
    print(f"Memory usage after gc.collect(): {mem_after_gc:.2f} MB")

    # 변화량 계산
    memory_change = mem_before_gc - mem_after_gc
    if memory_change > 0.001: # 매우 작은 변화도 감지하기 위해 임계값 조정
        print(f"Estimated memory freed by gc.collect(): {memory_change:.2f} MB")
    elif memory_change < -0.001:
        # 때때로 GC 자체의 오버헤드나 다른 요인으로 미미하게 증가할 수도 있습니다.
        print(f"Memory usage slightly increased by {-memory_change:.2f} MB after gc.collect().")
    else:
        print("No significant change in RSS memory usage detected after gc.collect().")
    print("Python garbage collection process complete.")
    print("-----------------------------")
    # 참고: 이 스크립트 자체에서는 gc.collect() 호출 직전에 많은 '쓰레기'를 생성하지 않으므로,
    # "freed memory"가 매우 작거나 0으로 나올 수 있습니다.
    # 실제 메모리 누수가 있거나 많은 임시 객체가 생성 후 해제되는 상황에서 더 큰 효과를 관찰할 수 있습니다.


def clear_system_cache_linux():
    """
    Linux 시스템의 페이지 캐시, dentry, inode 캐시를 비웁니다.
    주의: 시스템 성능에 일시적인 저하를 유발할 수 있습니다.
    루트 권한이 필요합니다.
    """
    print("\n--- Linux System Cache Cleanup ---")
    print("Attempting to clear system caches on Linux (requires sudo)...")
    print("This may temporarily slow down system performance as caches are rebuilt.")

    try:
        print("Running 'sync'...")
        subprocess.run(["sudo", "sync"], check=True, capture_output=True) # 에러 출력을 위해 capture_output 추가
        print("'sync' complete.")

        print("Running 'sysctl -w vm.drop_caches=3'...")
        process = subprocess.run(["sudo", "sysctl", "-w", "vm.drop_caches=3"], capture_output=True, text=True)

        if process.returncode == 0:
            print("System caches (page cache, dentries, inodes) dropped successfully.")
            if process.stdout:
                print(f"Output: {process.stdout.strip()}")
        else:
            print(f"Failed to drop system caches. Error code: {process.returncode}")
            if process.stderr:
                print(f"Error message: {process.stderr.strip()}")
            print("Please ensure you have sudo privileges and the command is correct.")
    except FileNotFoundError:
        print("Error: 'sudo', 'sync', or 'sysctl' command not found. Is this a Linux system with these utilities installed?")
    except subprocess.CalledProcessError as e:
        print(f"Error during system command execution: {e}")
        if e.stderr:
            print(f"Stderr: {e.stderr.decode().strip() if isinstance(e.stderr, bytes) else e.stderr.strip()}")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")
    print("--------------------------------")

def clear_memory_windows():
    """
    Windows에서 메모리 정리를 시도하는 방법은 제한적입니다.
    주로 특정 도구를 사용하거나, 여기서는 간단한 예시만 보여줍니다.
    (실질적인 OS 레벨 캐시 클리어는 파이썬만으로 어렵습니다)
    """
    print("\n--- Windows Memory Operations ---")
    # Windows에서는 파이썬으로 직접적인 시스템 캐시 클리어가 어렵습니다.
    # RAMMap (Sysinternals) 같은 도구를 사용하는 것이 일반적입니다.
    # 여기서는 파이썬 GC만 다시 한번 호출합니다.
    clear_python_memory() # 수정된 함수 호출
    print("For deeper memory cleaning on Windows, consider using tools like RAMMap from Sysinternals.")
    print("You can also try restarting non-essential applications.")
    print("-------------------------------")

if __name__ == "__main__":
    print("Starting memory cleanup process...")
    print(f"Initial memory usage of this script: {get_current_memory_usage():.2f} MB")

    # 1. 파이썬 내부 메모리 정리
    clear_python_memory()

    # 2. 운영체제별 시스템 캐시 정리 시도
    current_os = platform.system()
    print(f"\nOperating System detected: {current_os}")

    if current_os == "Linux":
        choice = input("Do you want to attempt to clear Linux system caches (page cache, dentries, inodes)? This requires sudo and may temporarily impact performance. (yes/no): ").lower()
        if choice == 'yes':
            clear_system_cache_linux()
        else:
            print("Skipping Linux system cache clearing.")
    elif current_os == "Windows":
        clear_memory_windows() # Windows 관련 함수 호출
    elif current_os == "Darwin": # macOS
        print("\n--- macOS System Cache ---")
        print("On macOS, system cache management is largely handled by the OS.")
        print("You can try 'sudo purge' in the terminal, but its effectiveness is debated.")
        print("Closing unused applications is generally recommended.")
        print("--------------------------")
    else:
        print(f"\nMemory clearing for {current_os} is not specifically implemented in this script beyond Python's GC.")

    print(f"\nFinal memory usage of this script: {get_current_memory_usage():.2f} MB")
    print("Memory cleanup process finished.")
    print("Note: True 'memory cleaning' at the OS level is complex.")
    print("This script primarily focuses on Python's GC and attempts system cache clearing on Linux (with caution).")