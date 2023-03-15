cmake_minimum_required(VERSION 3.21)
project(Social_Network___C)

set(CMAKE_CXX_STANDARD 14)

add_executable(Social_Network___C
        main.cpp Domain/User.cpp Domain/User.h UserInterface/UserInterface.cpp UserInterface/UserInterface.h Domain/Event.cpp Domain/Event.h Service/Network.cpp Service/Network.h "AbstractDataType(TAD)/List.h" "AbstractDataType(TAD)/OrderedMultitude.h" Domain/Chat.cpp Domain/Chat.h)
