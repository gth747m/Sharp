using System.Text;

namespace Sharp
{
    public static class Sharp
    {
        public static void Main(string[] args)
        {
            if (args.Length > 1)
            {
                Console.WriteLine("Usage: Sharp [script]");
                System.Environment.Exit(1);
            }
            else if (args.Length == 1)
            {
                RunFile(args[0]);
            }
            else
            {
                RunPrompt();
            }
        }

        public static void RunFile(string filename)
        {
            byte[] buffer = File.ReadAllBytes(filename);
            Run(Encoding.ASCII.GetString(buffer));
        }

        public static void RunPrompt()
        {
            using (StreamReader input = new StreamReader(Console.OpenStandardInput()))
            {
                string? line;
                while (true)
                {
                    Console.Write("> ");
                    line = input.ReadLine();
                    if ((line == null) || (line.Length == 0))
                        break;
                    Run(line);
                }
            }
        }

        public static void Run(string script)
        {
            Console.WriteLine(script);
        }

        public static void Error(int line, string message)
        {
            Report(line, "", message);
        }

        public static void Report(int line, string where, string message)
        {
            Console.WriteLine("[line " + line + "] Error" + where + ": " + message);
        }
    }
}