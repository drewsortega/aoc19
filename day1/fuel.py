import sys
import math

def module_fuel():
    total = 0
    for line in sys.stdin:
        try:
            fuel_weight = math.floor(int(line)/3)-2
            fuel_weight += extra_fuel(fuel_weight)
            total += fuel_weight
        except:
            pass
    return total

def extra_fuel(weight):
    added_fuel = math.floor(weight/3)-2
    if(added_fuel <= 0):
        return 0
    return added_fuel + extra_fuel(added_fuel)

def main():
    weight = module_fuel()
    print(weight)


if __name__ == "__main__":
    main()
