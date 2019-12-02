import sys
def parse_intcode(prog):
    # set program counter to 0
    pc = 0

    # loop until complete
    running = True
    while(running):
        # get opcode and increase program counter
        opcode = prog[pc]
        
        if opcode == 1:
            # store result
            prog[prog[pc+3]]=prog[prog[pc+1]]+prog[prog[pc+2]]
            pc += 4

        elif opcode == 2:
            # store result
            prog[prog[pc+3]]=prog[prog[pc+1]]*prog[prog[pc+2]]
            pc += 4

        elif opcode == 99:
            running = False
            pass
        else:
            sys.exit('received invalid opcode')
    return prog

def init(prog):
    prog[1] = 12
    prog[2] = 2
    return prog 


def main():
    prog = list()
    for line in sys.stdin:
        prog = prog + [int(x) for x in line.split(",")]
    
    prog = parse_intcode(init(prog))
    print(*prog)


if __name__ == "__main__":
    main()
