import sys
import math

def module_fuel():
    total = 0
    for line in sys.stdin:
        try:
            total += math.floor(int(line)/3)-2
        except:
            pass
    return total

def extra_fuel(weight):
    added_fuel = math.floor(int(weight)/3)-2
    if(added_fuel <= 0):
        return 0

    return added_fuel + extra_fuel(added_fuel)

def main():
    weight = module_fuel()
    weight += extra_fuel(weight)
    print(weight)


if __name__ == "__main__":
    main()
