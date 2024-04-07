class Matrix:
    def __init__(self, a, b):
        self.Row = a
        self.Column = b
        self.mat = [[0 for i in range(self.Column)] for j in range(self.Row)]
    def init(self):
        for i in range(self.Row):
            for j in range(self.Column):
                number = float(input(f"Matrix [{i}][{j}] : "))
                self.mat[i][j] = number
        self.print()
    def reverser3(self):
        determinant = 0
        for i in range(3):
            determinant += (self.mat[0][i] * (self.mat[1][(i+1)%3] * self.mat[2][(i+2)%3] - self.mat[1][(i+2)%3] * self.mat[2][(i+1)%3]))
        print(f"\ndeterminant: {determinant}\n")
        for i in range(3):
            for j in range(3):
                print(((self.mat[(j+1)%3][(i+1)%3] * self.mat[(j+2)%3][(i+2)%3]) - (self.mat[(j+1)%3][(i+2)%3] * self.mat[(j+2)%3][(i+1)%3]))/ determinant, end="\t")
            print("\n")
    def reverser2(self):
        Test3 = [[0 for i in range(2)] for j in range(2)]
        determinant = ((self.mat[0][0] * self.mat[1][1]) - (self.mat[0][1] * self.mat[1][0]))
        for i in range(self.Row):
            for j in range(self.Column):
                Test3[i][j] = ((self.mat[(j+1)%2][(i+1)%2] * self.mat[(j+2)%2][(i+2)%2]) - (self.mat[(j+1)%2][(i+2)%2] * self.mat[(j+2)%2][(i+1)%2]))/ determinant
        for i in range(self.Row):
            for j in range(self.Column):
                print(f" {Test3[i][j]} ", end="")
            print("\n")
    def Identity(self, num):
        for row in range(num):
            for col in range(num):
                if row == col:
                    print("1", end=" ")
                else:
                    print("0", end=" ")
            print("\n")
    def __add__(self, x):
        Test3 = Matrix(self.Row, self.Column)
        for i in range(self.Row):
            for j in range(self.Column):
                Test3.mat[i][j] = self.mat[i][j] + x.mat[i][j]
        Test3.print()
    def __sub__(self, x):
        Test3 = Matrix(self.Row, self.Column)
        for i in range(self.Row):
            for j in range(self.Column):
                Test3.mat[i][j] = self.mat[i][j] - x.mat[i][j]
        Test3.print()
    def __mul__(self, x):
        Test3 = Matrix(self.Row, self.Column)
        for i in range(self.Row):
            for j in range(self.Column):
                Test3.mat[i][j] = 0
                for k in range(self.Column):
                    Test3.mat[i][j] += self.mat[i][k] * (x.mat[k][j])
        Test3.print()
    def print(self):
        for i in range(self.Row):
            for j in range(self.Column):
                print(f" {self.mat[i][j]} ", end="")
            print("\n")
    def __del__(self):
        pass

while True:
    number = int(input("enter the number row and column\n"))
    Test = Matrix(number, number)
    Test.init()
    Test1 = Matrix(number, number)
    Test1.init()
    print("Addition of two given Matrices is : ")
    Test + Test1
    print("Subtraction of two given Matrices is : ")
    Test - Test1
    print("Multiplication of two given Matrices is : ")
    Test * Test1
    print("\nReversed Matrix 1\n")
    Test.reverser3()
    print("\nReversed Matrix 2\n")
    Test1.reverser2()
    c = input("\nDo you want to continue? (y/n)\n")
    if c.lower() == "n":
        break