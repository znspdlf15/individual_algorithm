def solution(N, stages):
    answer = []

    stage_list = []
    for i in range(0, N+2):
        stage_list.append(0)

    remain_player = len(stages)

    for stage in stages:
        stage_list[stage] += 1

    stage_failrate = []
    for i, stage in enumerate(stage_list):
        if i == 0 or i == N+1:
            continue
        if remain_player <= 0:
            temp = [i, 0]
        else:
            temp = [i, stage/(float(remain_player))]
        remain_player -= stage
        stage_failrate.append(temp)

    # sort stage_failrate
    stage_failrate2 = sorted(stage_failrate, key=lambda stage: stage[0])
    stage_failrate2.reverse()
    stage_failrate2 = sorted(stage_failrate2, key=lambda stage: stage[1])
    stage_failrate2.reverse()

    print(stage_failrate2)
    for i in range(0, len(stage_failrate2)):
        answer.append(stage_failrate2[i][0])

    return answer

N = 5
stages = [2, 1, 2, 6, 2, 4, 3, 3]
N = 4
stages = [4, 4, 4, 4, 4]
ans = solution(N, stages)
print(ans)