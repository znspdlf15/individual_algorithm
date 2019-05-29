def isUniqueRelation(relation, idxs):
    dic = {}

    for i in range(0, len(relation)):
        key_str = ""
        for x in idxs:
            key_str += relation[i][x]

        if dic.get(key_str) is not None:
            return False

        dic[key_str] = True

    return True

def get_powerset(A):
    A_size = len(A)
    A_pow = []
    for i in range(2**A_size):
        flag = bin(i)[2:].zfill(A_size)
        subset = [A[j] for j in range(A_size) if flag[j] == '1']
        A_pow.append(subset)
    return A_pow

def solution(relation):
    answer = 0

    q = []
    dic = {}

    for i in range(0, len(relation[0])):
        q.append(i)

    power_set = get_powerset(q)
    q = sorted(power_set, key=len)

    while len(q):
        if len(q[0]) == 0:
            q.pop(0)
            continue

        if isUniqueRelation(relation, q[0]):
            key_str = ""
            print(q[0])
            for i in range(0, len(q[0])):
                key_str += str(q[0][i])
                if dic.get(key_str) is not None:
                    q.pop(0)
                    break
            else:
                dic[key_str] = True
                q.pop(0)
                continue

        q.pop(0)
        q = sorted(q, key=len)

    return len(dic)

relation = [["100","ryan","music","2"],["200","apeach","math","2"],["300","tube","computer","3"],["400","con","computer","4"],["500","muzi","music","3"],["600","apeach","music","2"]]
print(solution(relation))