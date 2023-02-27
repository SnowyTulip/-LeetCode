def get_all():
    obj = [(1,15),(3,20),(4,30)]
    max_w = 4
    dp = [0 for j in range(5)]
    
    for i in range(0,3):
        for j in range(4,obj[i][0]-1,-1):
            dp[j] = max(dp[j-obj[i][0]] + obj[i][1],dp[j])
    return dp[4]

    
print(get_all())
