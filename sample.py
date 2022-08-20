def smallestNumber(pattern):
    
    minimum = ['1', '2', '3', '4', '5', '6', '7', '8', '9'][::-1]
    i = 0
    ans = ''
    
    while i < len(pattern):
        print(ans, minimum)

        if pattern[i] == 'I':
            ans += minimum.pop()
            i += 1
        
        else:
            count = 1

            
            if i == len(pattern)-1:
                return ans + ''.join(minimum[-2:])

            tmp = minimum.pop()
            while pattern[i] == pattern[i+1]:
                count += 1
                i += 1
                if i == len(pattern) - 1:
                    break
            
            ans += ''.join(minimum[-count:])
            
            for _ in range(count):
                minimum.pop()
                
            minimum.append(tmp)
            i += 1
            
    
    return ans + minimum.pop()


pattern = "DD"

print(smallestNumber(pattern))