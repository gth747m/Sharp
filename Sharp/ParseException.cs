using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sharp
{
    public class ParseException : Exception
    {
        public ParseException(Token token, string message)
        {
            Sharp.Error(token, message);
        }
    }
}
