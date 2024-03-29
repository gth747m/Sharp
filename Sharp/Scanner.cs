namespace Sharp
{
    public class Scanner
    {
        private string _source;
        private List<Token> _tokens = new List<Token>();
        private int _start = 0;
        private int _current = 0;
        private int _line = 0;
        private Dictionary<string, TokenType> _keywords = new Dictionary<string, TokenType>() 
        {
            { "and",    TokenType.AND },
            { "class",  TokenType.CLASS },
            { "else",   TokenType.ELSE },
            { "false",  TokenType.FALSE },
            { "for",    TokenType.FOR },
            { "fun",    TokenType.FUN },
            { "if",     TokenType.IF },
            { "nil",    TokenType.NIL },
            { "or",     TokenType.OR },
            { "print",  TokenType.PRINT },
            { "return", TokenType.RETURN },
            { "super",  TokenType.SUPER },
            { "this",   TokenType.THIS },
            { "true",   TokenType.TRUE },
            { "var",    TokenType.VAR },
            { "while",  TokenType.WHILE },
        };

        public Scanner(string source)
        {
            _source = source;
        }

        public List<Token> ScanTokens()
        {
            while (!IsAtEnd())
            {
                _start = _current;
                ScanToken();
            }
            return _tokens;
        }

        private void AddToken(TokenType type, object? literal = null)
        {
            _tokens.Add(new Token(type, _source.Substring(_start, _current), literal, _line));
        }

        private void ScanToken() {
            char c = Advance();
            switch (c)
            {
                case '(': AddToken(TokenType.LEFT_PAREN); break;
                case ')': AddToken(TokenType.RIGHT_PAREN); break;
                case '{': AddToken(TokenType.LEFT_BRACE); break;
                case '}': AddToken(TokenType.RIGHT_BRACE); break;
                case ',': AddToken(TokenType.COMMA); break;
                case '.': AddToken(TokenType.DOT); break;
                case '-': AddToken(TokenType.MINUS); break;
                case '+': AddToken(TokenType.PLUS); break;
                case ';': AddToken(TokenType.SEMICOLON); break;
                case '*': AddToken(TokenType.STAR); break;
                case '!':
                    AddToken(Match('=') ? TokenType.BANG_EQUAL : TokenType.BANG);
                    break;
                case '=':
                    AddToken(Match('=') ? TokenType.EQUAL_EQUAL : TokenType.EQUAL);
                    break;
                case '<':
                    AddToken(Match('=') ? TokenType.LESS_EQUAL : TokenType.LESS);
                    break;
                case '>':
                    AddToken(Match('=') ? TokenType.GREATER_EQUAL : TokenType.GREATER);
                    break;
                case '/':
                    // If this is a comment
                    if (Match('/'))
                    {
                        // skip until the end of line
                        while (Peek() != '\n' && !IsAtEnd())
                        {
                            Advance();
                        }
                    }
                    else
                    {
                        AddToken(TokenType.SLASH);
                    }
                    break;
                case ' ':
                case '\r':
                case '\t':
                    break;
                case '\n':
                    _line++;
                    break;
                case '"':
                    GetString();
                    break;
                default:
                    if (IsDigit(c))
                    {
                        GetNumber();
                    }
                    else if (IsAlpha(c))
                    {
                        GetIdentifier();
                    }
                    else
                    {
                        Sharp.Error(_line, "Unexpected character '" + c + "'.");
                    }
                    break;
            }
        }

        private bool IsAtEnd()
        {
            return _current >= _source.Length;
        }

        private bool IsDigit(char c)
        {
            return c >= '0' && c <= '9';
        }

        private bool IsAlpha(char c)
        {
            return ((c >= 'a' && c <= 'z') ||
                    (c >= 'A' && c <= 'Z') ||
                    (c == '_'));
        }

        private bool IsAlphaNumeric(char c)
        {
            return IsDigit(c) || IsAlpha(c);
        }

        private char Advance()
        {
            return _source.ElementAt(_current++);
        }

        private char Peek()
        {
            if (IsAtEnd())
                return '\0';
            return _source.ElementAt(_current);
        }

        private char PeekNext()
        {
            if (_current + 1 >= _source.Length)
                return '\0';
            return _source.ElementAt(_current + 1);
        }

        private void GetString()
        {
            while (Peek() != '"' && !IsAtEnd())
            {
                if (Peek() == '\n')
                {
                    _line++;
                }
                Advance();
            }
            if (IsAtEnd())
            {
                Sharp.Error(_line, "Unterminated string.");
            }
            Advance();
            AddToken(TokenType.STRING, _source.Substring(_start + 1, _current - 1));
        }

        private void GetNumber()
        {
            while (IsDigit(Peek()))
            {
                Advance();
            }
            if (Peek() == '.' && IsDigit(PeekNext()))
            {
                Advance();
            }
            while (IsDigit(Peek()))
            {
                Advance();
            }
            AddToken(TokenType.NUMBER, Double.Parse(_source.Substring(_start, _current)));
        }

        private void GetIdentifier()
        {
            while (IsAlphaNumeric(Peek()))
            {
                Advance();
            }
            var text = _source.Substring(_start, _current);
            if (_keywords.ContainsKey(text))
            {
                AddToken(_keywords[text]);
            }
            else
            {
                AddToken(TokenType.IDENTIFIER);
            }
        }

        private bool Match(char expectedChar)
        {
            if (IsAtEnd())
            {
                return false;
            }
            if (_source.ElementAt(_current) != expectedChar)
            {
                return false;
            }
            _current++;
            return true;
        }
    }
}