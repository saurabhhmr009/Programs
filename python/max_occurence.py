# Program to find out the no of occurence of the max element in the list. 


#def birthdayCakeCandles(candles):
#    length  = int(len(candles))
#    tallest = max(candles)
#    occurence = 0;
#    for i in range (length):
#        if candles[i] == tallest:
#            occurence += 1;
#    return occurence

def birthdayCakeCandles(candles):
    return candles.count(max(candles))

if __name__ == '__main__' :
    candles = []
    candles = list(map(int, input().split()))
    occurence = birthdayCakeCandles(candles)
    print(occurence)
