public class Q3{
    public static boolean issafe(char board[][] , int row, int col){
        // vertically up
        for(int i = row -1; i >= 0; i--){
            if(board[i][col] == 'Q'){
                return false;
            }
        }
        //diagonally left
        for(int i = row-1, j = col-1; i >= 0 && j>=0; i-- , j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        //diagonally right
        for(int i = row-1 , j = col +1; i >= 0 && j < board.length; i--,j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    public static boolean nQueens(char board[][], int row){
        // base case
        if(row == board.length){
            // printboard(board);
           
            return true;
        }
        // column loop 
        for(int j =0; j<board.length; j++){
            if(issafe(board, row , j)){
            board[row][j] = 'Q';
            if(nQueens(board, row+1)){
                return true;
            } // function call
            board[row][j] = '.'; // backtracking
            }
        }
        return false;
    }
    public static void printboard(char board[][]){
        System.out.println("----------------chess---------------");
        for(int i = 0; i<board.length; i++){
            for(int j = 0; j < board.length; j++){
                System.out.print(board[i][j] + " ");
            }
            System.out.println("");
        }
    }
    public static void main(String[] args) {
        int n =6;
        char board[][] = new char[n][n];
        // inttialize
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                board[i][j] = '.';
            }
        }
       if( nQueens(board,0)){
        System.out.println("Solution is possible");
        printboard(board);
       }
       else{
        System.out.println("Solution is not possible");
       }

    }
}
