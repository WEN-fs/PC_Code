import random
import string

def generate_strings(count=100, length=7, fixed_positions={1: 'e', 5: 'd'}, exclude_chars='tyuiopglcvbnm'):
    possible_chars = [char for char in string.ascii_lowercase if char not in exclude_chars]
    results = []
    
    while len(results) < count:
        result = ''
        for i in range(length):
            if i in fixed_positions:
                result += fixed_positions[i]
            else:
                result += random.choice(possible_chars)
        
        if all(result[int(i)] == fixed_positions[i] for i in fixed_positions):
            results.append(result)
    
    return results
results = generate_strings()

# 打印结果
for result in results:
    print(result)