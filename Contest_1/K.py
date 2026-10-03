#Soma dos digitos até len() = 1

num = input()

ans = 0

if len(num) > 1:
    while True:
        result = 0
        for x in num:
            result += int(x)

        ans += 1

        if len(str(result)) != 1:
            num = str(result)
        else:
            break

print(ans)