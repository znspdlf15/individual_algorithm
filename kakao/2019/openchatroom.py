def solution(record):
    answer = []

    uid_dic = {}

    for i in range(0, len(record)):
        commands = record[i].split(' ')

        temp = ""
        if commands[0] == "Change":
            uid_dic[commands[1]] = commands[2]
        else:
            temp += commands[1]
            if commands[0] == "Enter":
                uid_dic[commands[1]] = commands[2]
                temp += "님이 들어왔습니다."
            elif commands[0] == "Leave":
                temp += "님이 나갔습니다."

            answer.append(temp)

    for i in range(0, len(answer)):
        commands = answer[i].split("님")

        answer[i] = "{}{}".format(uid_dic[commands[0]], '님'+commands[1])

    return answer

input_strs = ["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]
output_strs = solution(input_strs)

print(output_strs)