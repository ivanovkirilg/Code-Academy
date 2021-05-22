class WordSort():
    def getInput(self):
        i_str = input()
        i_list = i_str.split(',')
        print('received:', i_list) # debug
        i_list.sort()
        return i_list
