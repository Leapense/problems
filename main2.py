import subprocess
import platform

def get_swappiness_linux():
    """Linux 시스템의 현재 swappiness 값을 반환합니다. 실패 시 None을 반환합니다."""
    if platform.system() != "Linux":
        print("Swappiness is a Linux-specific concept.")
        return None

    try:
        # /proc 파일 시스템을 직접 읽는 방법
        with open('/proc/sys/vm/swappiness', 'r') as f:
            swappiness_value = int(f.read().strip())
            return swappiness_value
    except FileNotFoundError:
        print("Could not find /proc/sys/vm/swappiness. Trying with sysctl.")
        # sysctl 명령어를 사용하는 방법 (대안)
        try:
            process = subprocess.run(['sysctl', '-n', 'vm.swappiness'], capture_output=True, text=True, check=True)
            swappiness_value = int(process.stdout.strip())
            return swappiness_value
        except FileNotFoundError:
            print("sysctl command not found.")
            return None
        except subprocess.CalledProcessError as e:
            print(f"Error running sysctl: {e}")
            return None
        except ValueError:
            print("Could not parse swappiness value from sysctl output.")
            return None
    except ValueError:
        print("Could not parse swappiness value from /proc file.")
        return None
    except Exception as e:
        print(f"An unexpected error occurred: {e}")
        return None

if __name__ == "__main__":
    if platform.system() == "Linux":
        current_swappiness = get_swappiness_linux()
        if current_swappiness is not None:
            print(f"Current swappiness value: {current_swappiness}")
            if current_swappiness < 10:
                print("Swappiness is low: System will try to avoid swapping as much as possible.")
            elif current_swappiness > 60:
                print("Swappiness is high: System may swap more aggressively.")
            else:
                print("Swappiness is in a typical range (e.g., default is often 60).")
    else:
        print(f"Swappiness is primarily a Linux concept. Your OS: {platform.system()}")