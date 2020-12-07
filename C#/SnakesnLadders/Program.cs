using System;
using System.Collections.Generic;

namespace Solution
{
    class Vertex
    {
        public int num;
        public int distance = 0;
    }

    class Solution
    {
        public static int getMinMoves(int[] moves)
        {
            Queue<Vertex> queue = new Queue<Vertex>();

            bool[] visited = new bool[100];
            for (int i = 0; i < 100; i++)
            {
                visited[i] = false; // not visited
            }

            Vertex start = new Vertex() { num = 0, distance = 0 }; // 0 means number 1
            
            visited[0] = true;
            queue.Enqueue(start);

            Vertex current = null;
            while (queue.Count != 0)
            {
                current = queue.Dequeue();

                if (current.num == 99)
                {
                    break;
                }
                
                int num = current.num;
                int dist = current.distance;
                current = null;

                for (int i = num+1; i <= num + 6 && i < 100; ++i)
                {
                    if (visited[i] != true) // if not visited
                    {
                        visited[i] = true;
                        Vertex nxt = new Vertex() { distance = dist + 1 };

                        if (moves[i] != -1)
                        {
                            nxt.num = moves[i];
                        }
                        else
                        {
                            nxt.num = i;
                        }

                        queue.Enqueue(nxt);
                    }
                }
            }

            if(current == null)
            {
                return -1;
            }

            return current.distance;
        }

        public static void Main()
        {
            int n = 0, s = 0, l = 0; // n: number of test cases, s: number of snakes, l : number of ladders

            n = Convert.ToInt32(Console.ReadLine().Trim());
            while (n > 0)
            {
                n--;

                int[] moves = new int[100]; // all snakes and ladders

                for (int i = 0; i < 100; i++) { moves[i] = -1; }
                // scan the ladders
                l = Convert.ToInt32(Console.ReadLine());
                for (int i = 0; i < l; i++)
                {
                    int from = 0, to = 0;
                    string[] parts = Console.ReadLine().Trim().Split(new char[] { ' ' });
                    from = Convert.ToInt32(parts[0]);
                    to = Convert.ToInt32(parts[1]);
                    moves[--from] = --to;
                }

                // scan the snakes
                s = Convert.ToInt32(Console.ReadLine());
                for (int i = 0; i < s; i++)
                {
                    int from = 0, to = 0;
                    string[] parts = Console.ReadLine().Trim().Split(new char[] { ' ' });
                    from = Convert.ToInt32(parts[0]);
                    to = Convert.ToInt32(parts[1]);
                    moves[--from] = --to;
                }

                Console.WriteLine("Answer: " + getMinMoves(moves));
                Console.ReadKey();
            }
        }
    }
}