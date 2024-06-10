import nltk
from nltk.corpus import words

# 下载单词列表
nltk.download('words')

# 获取英语单词列表
word_list = words.words()

# 定义我们的特定位置和字母
positions = {1:'e', 5:'d'} 

# 特定位置不允许出现的字母
avoid_at_positions = {}

# 定义我们想要在单词中找到的其他字母
other_letters = ['a', 'e', 'r', 'd']

# 定义我们不希望在单词中出现的字母
avoid_letters = []

# 定义单词的期望长度
word_length = 7

# 查找匹配的单词
result = [word for word in word_list 
          if len(word) == word_length
          and all(word[pos] == letter for pos, letter in positions.items() if pos < word_length)
          and all(letter in word for letter in other_letters)
          and not any(word[pos] == letter for pos, letter in avoid_at_positions.items() if pos < word_length)
          and not any(letter in word for letter in avoid_letters)]

print(result)