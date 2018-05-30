for _ in range(10):
    t = input()
    s = input()
    words = s.split()
    word = len(words)
    message = []
    if t == "encode":
        maxlength = 0
        for i in range(word):
            maxlength = max(maxlength, len(words[i]))
        for i in range(maxlength):
            for j in range(word):
                if i < len(words[j]):
                    message.append(words[j][i])
        pointer = 0
        for i in range(word):
            for j in range(len(words[i])):
                print(message[pointer], end = "")
                pointer+=1
            print(" ", end = "")
    else:
        for _ in range(word):
            message.append("")
        pointer = 0
        for i in range(word):
            for j in range(len(words[i])):
                while len(message[pointer]) == len(words[pointer]):
                    pointer = (pointer+1)%word
                message[pointer] += words[i][j]
                pointer = (pointer+1)%word
        for w in message:
            print(w, end = " ")
    print()