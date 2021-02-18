class Person:
    def __init__(self, firstName, lastName, idNumber):
        self.firstName = firstName
        self.lastName = lastName
        self.idNumber = idNumber
    
    def printPerson(self):
        print("Name:", self.lastName + ",", self.firstName)
        print("ID:", self.idNumber)

class Student(Person):
    def __init__(self, firstName, lastName, idNumber,scores):
        Person.__init__(self,firstName, lastName, idNumber)
        self.scores = scores
    
    def calculate(self):
        sum = 0;
        length = len(self.scores)
        for i in range(length):
            sum += self.scores[i]
        average  = sum/length
        if(average >= 90) and (average <= 100):
            return "O"
        elif(average >= 80) and (average < 90):
            return "E"
        elif(average >= 70) and (average < 80):
            return "A"
        elif(average >= 55) and (average < 70):
            return "P"
        elif(average >= 40) and (average < 55):
            return "D"
        elif(average <40):
            return "T"
        else:
            pass




if __name__ == '__main__':
    student = input().split()
    firstName = student[0]
    lastName = student[1]
    idNumber = student[2]
    
    num_testscores = int(input())
    scores = list(map(int, input().split()))
    s = Student(firstName, lastName, idNumber, scores)
    s.printPerson()
    print("Grade:",s.calculate())
    
