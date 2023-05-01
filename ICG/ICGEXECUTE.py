import re

def execute_icg(parsed_icg):
    variables = {}
    functions = {}

    def get_value(val):
        # check if the value is a variable or a constant
        if isinstance(val, str) and val.startswith('t'):
            return variables[val]
        else:
            return val

    def execute_instruction(instr):
        opcode, args = instr[0], instr[1:]
        if opcode == 'LABEL':
            pass # do nothing
        elif opcode == 'GOTO':
            return functions[args[0]]
        elif opcode == 'IFFALSE':
            val1 = get_value(args[0])
            if not val1:
                return functions[args[1]]
        elif opcode == 'PRINT':
            val1 = get_value(args[0])
            print(val1)
        elif opcode == 'ASSIGN':
            variables[args[1]] = get_value(args[0])
        elif opcode == 'PLUS':
            val1, val2 = get_value(args[0]), get_value(args[1])
            variables[args[2]] = val1 + val2
        elif opcode == 'MINUS':
            val1, val2 = get_value(args[0]), get_value(args[1])
            variables[args[2]] = val1 - val2
        elif opcode == 'MULT':
            val1, val2 = get_value(args[0]), get_value(args[1])
            variables[args[2]] = val1 * val2
        elif opcode == 'DIV':
            val1, val2 = get_value(args[0]), get_value(args[1])
            variables[args[2]] = val1 / val2
        elif opcode == 'MOD':
            val1, val2 = get_value(args[0]), get_value(args[1])
            variables[args[2]] = val1 % val2
        elif opcode == 'CALL':
            func = functions[args[0]]
            ret_val = execute_function(func, args[1:])
            if args[-1].startswith('t'):
                variables[args[-1]] = ret_val
        else:
            raise ValueError(f'Unknown opcode: {opcode}')

    def execute_function(func, args):
        for i, arg in enumerate(args):
            if isinstance(arg, str) and arg.startswith('t'):
                args[i] = variables[arg]
        for instr in func:
            ret_val = execute_instruction(instr)
            if ret_val is not None:
                return ret_val

    # parse function definitions and store them in functions dictionary
    for func in parsed_icg:
        if func[0] == 'FUNC':
            func_name = func[1]
            func_instr = func[2:]
            functions[func_name] = func_instr

    # execute the main function
    execute_function(functions['main'], [])

# example usage
if __name__ == '__main__':
    with open('ICG.txt', 'r') as f:
        icg = f.read()

    # parse the icg string
    parsed_icg = []
    for line in icg.split('\n'):
        parsed_line = re.findall(r'"([^"]+)"|(\w+)', line)
        parsed_line = [val if val != '' else opcode for val, opcode in parsed_line]
        parsed_icg.append(parsed_line)

    execute_icg(parsed_icg)
