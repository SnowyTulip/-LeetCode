with open("导师.txt",'r',encoding='utf-8') as f:
    file = open("导师_s.txt",'r+',encoding="utf-8")
    title = ""
    res = [s.strip('\n') for s in file.readlines()]
    for line in f.readlines():
        line = line.strip('\n')
        if line[0] == '#':
            title = "".join(line[1:])
        elif line in res:
            print("{}:{}".format(title,line))
        # print(res)
