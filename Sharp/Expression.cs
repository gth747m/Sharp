using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sharp
{
    public abstract class Expression
    {
        public abstract T Accept<T>(Visitor<T> visitor);
    }
}
