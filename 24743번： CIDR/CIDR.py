class CIDRCalculator:
    def __init__(self, ip_list):
        self.ip_ints = [self.ip_to_int(ip) for ip in ip_list]

    def ip_to_int(self, ip):
        parts = list(map(int, ip.split('.')))
        return (parts[0] << 24) | (parts[1] << 16) | (parts[2] << 8) | parts[3]
    
    def compute_prefix_length(self):
        min_ip = min(self.ip_ints)
        max_ip = max(self.ip_ints)
        xor = min_ip ^ max_ip
        if xor == 0:
            return 32
        bit_length = xor.bit_length()
        prefix = 32 - bit_length
        return prefix if prefix > 0 else 32
    
import sys

def main():
    n, *ips = sys.stdin.read().split()
    calculator = CIDRCalculator(ips)
    print(calculator.compute_prefix_length())

if __name__ == "__main__":
    main()