namespace Sharp
{
    public enum TokenType
    {
        #region Separators
        LEFT_PAREN,
        RIGHT_PAREN,
        LEFT_BRACE,
        RIGHT_BRACE,
        COMMA,
        SEMICOLON,
        #endregion
        #region Math
        DOT,
        MINUS,
        PLUS,
        SLASH,
        STAR,
        #endregion
        #region Comparison
        BANG,
        BANG_EQUAL,
        EQUAL,
        EQUAL_EQUAL,
        GREATER,
        GREATER_EQUAL,
        GREATER_GREATER,
        LESS,
        LESS_EQUAL,
        LESS_LESS,
        #endregion
        #region Literals
        IDENTIFIER,
        STRING,
        NUMBER,
        #endregion
        #region Keywords
        AND,
        CLASS,
        ELSE,
        FALSE,
        FUN,
        FOR,
        IF,
        NIL,
        OR,
        PRINT,
        RETURN,
        SUPER,
        THIS,
        TRUE,
        VAR,
        WHILE,
        EOF,
        #endregion
    }
}