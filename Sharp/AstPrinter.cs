using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sharp
{
    public class AstPrinter : Visitor<string>
    {
        public string VisitBinaryExpr(Binary expr)
        {
            return Parenthesize(expr.Operator.Lexeme, expr.Left, expr.Right);
        }

        public string VisitGroupingExpr(Grouping expr)
        {
            return Parenthesize("group", expr.Expression);
        }

        public string VisitLiteralExpr(Literal expr)
        {
            return expr.Value.ToString() ?? "nil";
        }

        public string VisitUnaryExpr(Unary expr)
        {
            return Parenthesize(expr.Operator.Lexeme, expr.Right);
        }

        public string Print(Expression expression)
        {
            return expression.Accept(this);
        }

        private string Parenthesize(string name, params Expression[] expr)
        {
            StringBuilder sb = new StringBuilder();
            sb.Append("(").Append(name);
            foreach (var ex in expr)
            {
                sb.Append(" ");
                sb.Append(ex.Accept(this));
            }
            sb.Append(")");
            return sb.ToString();
        }
    }
}
