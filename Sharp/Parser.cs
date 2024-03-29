﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sharp
{
    public class Parser
    {
        private List<Token> _tokens;
        private int _current = 0;

        public Parser(List<Token> tokens)
        {
            _tokens = tokens;
        }

        private Expression Expression()
        {
            return Equality();
        }

        private Expression Equality()
        {
            Expression expr = Comparison();
            while (Match(TokenType.BANG_EQUAL, TokenType.EQUAL_EQUAL))
            {
                Token @operator = previous();
                Expression right = Comparison();
                expr = new Binary(expr, @operator, right);
            }
            return expr;
        }

        private Expression Comparison()
        {
            Expression expr = Term();
            while (Match(TokenType.GREATER, TokenType.GREATER_EQUAL, TokenType.LESS, TokenType.LESS_EQUAL))
            {
                Token @operator = Previous();
                Expression right = Term();
                expr = new Binary(expr, @operator, right);
            }
            return expr;
        }

        private Expression Term()
        {
            Expression expr = Factor();
            while (Match(TokenType.MINUS, TokenType.PLUS))
            {
                Token @operator = Previous();
                Expression right = Factor();
                expr = new Binary(expr, @operator, right);
            }
            return expr;
        }

        private Expression Factor()
        {
            Expression expr = Unary();
            while (Match(TokenType.SLASH, TokenType.STAR))
            {
                Token @operator = Previous();
                Expression right = Unary();
                expr = new Binary(expr, @operator, right);
            }
            return expr;
        }

        private Expression Unary()
        {
            if (Match(TokenType.BANG, TokenType.MINUS))
            {
                Token @operator = Previous();
                Expression right = Unary();
                return new Unary(@operator, right);
            }
            return Primary();
        }

        private Expression Primary()
        {
            if (Match(TokenType.FALSE))
                return new Literal(false);
            if (Match(TokenType.TRUE))
                return new Literal(true);
            if (Match(TokenType.NIL))
                return new Literal(null);
            if (Match(TokenType.NUMBER, TokenType.STRING))
                return new Literal(Previous().Literal);
            if (Match(TokenType.LEFT_PAREN))
            {
                Expression expr = Expression();
                Consume(TokenType.RIGHT_PAREN, "Expected a ')' after expression.");
                return new Grouping(expr);
            }
            throw new NotImplementedException();
        }

        private bool Match(params TokenType[] types)
        {
            foreach (TokenType type in types)
            {
                if (Check(type))
                {
                    Advance();
                    return true;
                }
            }
            return false;
        }

        private bool Check(TokenType type)
        {
            if (IsAtEnd())
            {
                return false;
            }
            return Peek().Type == type;
        }

        private Token Advance()
        {
            if (!IsAtEnd())
            {
                _current++;
            }
            return Previous();
        }

        private Token Consume(TokenType type, string message)
        {
            if (Check(type))
            {
                return Advance();
            }
            throw new ParseException(Peek(), message);
        }

        private bool IsAtEnd()
        {
            return Peek().Type == TokenType.EOF;
        }

        private Token Peek()
        {
            return _tokens.ElementAt(_current);
        }

        private Token Previous()
        {
            return _tokens.ElementAt(_current - 1);
        }

        private void Synchronize()
        {
            Advance();
            while (!IsAtEnd())
            {
                if (Previous().Type == TokenType.SEMICOLON)
                {
                    return;
                }
                switch (Peek().Type)
                {
                    case TokenType.CLASS:
                    case TokenType.FOR:
                    case TokenType.FUN:
                    case TokenType.IF:
                    case TokenType.PRINT:
                    case TokenType.RETURN:
                    case TokenType.VAR:
                    case TokenType.WHILE:
                        return;
                }
                Advance();
            }
        }
    }
}
