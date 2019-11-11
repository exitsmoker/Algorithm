def solution(board, moves):
    boardStack = [[]*30]
    for i in range(len(board)):
        for j in range(len(board[i])):
            if len(boardStack[i]) == 0:
                boardStack += [board[i][j]]
            else:
                boardStack[i].append(board[i][j])
    
    print(boardStack)
    print(board)
    print(moves)

solution([[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]], [1,5,3,5,1,2,1,4])