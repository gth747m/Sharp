using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sharp
{
    public class Unary : Expression
    {
        public Token Operator;
        public Expression Right;

        public Unary(Token @operator, Expression right)
        {
            Operator = @operator;
            Right = right;
        }

        public override T Accept<T>(Visitor<T> visitor)
        {
            return visitor.VisitUnaryExpr(this);
        }
    }
}
