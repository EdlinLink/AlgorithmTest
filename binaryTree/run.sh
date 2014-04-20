g++ main.cpp -o out
./out 2> graph.dot
dot -Tjpg graph.dot -o graph.jpg
open graph.jpg
