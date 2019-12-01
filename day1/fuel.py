import sys
import math

def main():
    total = 0
    for line in sys.stdin:
        try:
            total += math.floor(int(line)/3)-2
        except:
            pass
    print(total)

if __name__ == "__main__":
    main()
