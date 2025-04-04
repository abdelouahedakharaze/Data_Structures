def matrixSpiral(n):
    matrix = [[0] * n for _ in range(n)]
    x, y = 0, 0
    dx, dy = 0, 1  
    for i in range(1, n * n + 1):
        matrix[x][y] = i
        nx, ny = x + dx, y + dy
        if 0 <= nx < n and 0 <= ny < n and matrix[nx][ny] == 0:
            x, y = nx, ny
        else:
            dx, dy = dy, -dx
            x, y = x + dx, y + dy
    return matrix
if __name__ == "__main__":
    for i in range (4,7):
        c= matrixSpiral(i)
        for line in c:
            print(line)
        print("=================")
   
