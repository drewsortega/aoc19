import sys

def get_val(pc_addr, mode, prog):
    if(mode == 0):
        return prog[prog[pc_addr]]
    elif(mode == 1):
        return prog[pc_addr]
    else:
        sys.exit('bad mode')

def parse_intcode(prog):
    size = len(prog)
    # set program counter to 0
    pc = 0

    # loop until complete
    running = True
    while(running):
        # ABCDE
        inst = prog[pc]
        # get DE
        # get opcode and increase program counter

        opcode = inst % 100 

        # update instruction, so we can get ABC.
        inst = int(inst / 100)

        C_mode = inst % 10
        inst = int(inst / 10)
            
        B_mode = inst % 10
        inst = int(inst / 10)

        A_mode = inst % 10

        A_val = 0
        B_val = 0
        C_val = 0
        if(pc + 1 < size):
            A_val = get_val(pc+1, A_mode, prog)
            if(pc + 2 < size - 1):
                B_val = get_val(pc+2, B_mode, prog)
                if(pc + 3 < size - 1):
                    C_val = get_val(pc+3, C_mode, prog)
            
        
        # addition
        if opcode == 1:
            # store result
            prog[prog[pc+3]]=A_val + B_val
            pc += 4

        # multiplication
        elif opcode == 2:
            # store result
            prog[prog[pc+3]]=A_val * B_val
            pc += 4

        elif opcode == 3:
            prog[prog[pc+1]] = input()
            pc += 2
        
        elif opcode == 4:
            print(A_val)
            pc += 2

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
    prog = prog + [int(x) for x in input().split(",")]
    parse_intcode(prog)

if __name__ == "__main__":
    main()

