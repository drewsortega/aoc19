import sys

def parse_intcode(prog):
    # set program counter to 0
    pc = 0

    # loop until complete
    running = True
    while(running):
        # get opcode and increase program counter
        opcode = prog[pc]
        
        # addition
        if opcode == 1:
            # store result
            prog[prog[pc+3]]=prog[prog[pc+1]]+prog[prog[pc+2]]
            pc += 4

        # multiplication
        elif opcode == 2:
            # store result
            prog[prog[pc+3]]=prog[prog[pc+1]]*prog[prog[pc+2]]
            pc += 4

        # end of execution
        elif opcode == 99:
            running = False

        # invalid opcode
        else:
            sys.exit('received invalid opcode')
    return prog

def init(prog, noun, verb):
    # set initial state
    prog[1] = noun
    prog[2] = verb
    return prog 


def main():
    prog = list()
    for line in sys.stdin:
        prog = prog + [int(x) for x in line.split(",")]
    noun = 0
    res = 0
    while(True):
        new_res = parse_intcode(init(prog.copy(), noun+1, 0))[0]
        if(new_res > 19690720):
            break;
        res = new_res
        noun += 1

    print(100*noun+(19690720-res))

if __name__ == "__main__":
    main()
