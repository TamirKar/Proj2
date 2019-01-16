cmake_minimum_required(VERSION 3.13)
project(untitled19)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-pthread")
add_executable(untitled19 main.cpp Vertex.cpp Vertex.h Searchable.h Searcher.h MatrixSearchable.cpp MatrixSearchable.h DFS.cpp DFS.h BestFirstSearch.cpp BestFirstSearch.h BFS.cpp BFS.h AStar.cpp AStar.h Solver.h MyTestClientHandler.cpp MyTestClientHandler.h ClientHandler.h CacheManager.h FileCacheManager.cpp FileCacheManager.h MySolver.cpp MySolver.h Server.h MySerialServer.cpp MySerialServer.h ServerClientArgs.h DataReaderServer.cpp DataReaderServer.h DataReaderClient.cpp DataReaderClient.h)