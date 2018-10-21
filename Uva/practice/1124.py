while(True):
    inp = ''
    try:
        inp = input()
    except EOFError:
        break
    print(inp)
    # inp = input()
    # if inp="":
    #     break
    # print(inp) 