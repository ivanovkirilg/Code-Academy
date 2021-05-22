class Words():
    def getWords(self):
        i_str = input()
        i_set = set(i_str.split(' '))
        result = list(i_set)
        result.sort()
        return result
