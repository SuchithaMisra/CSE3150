#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MatrixModified.h" 

TEST_CASE("Matrix:Multiplication") {
    std::vector<std::vector<int>> D_0 = {{0, 2, 2, 2},
                                         {2, 0, 2, 2},
                                         {2, 2, 0, 2},
                                         {2, 2, 2, 0}};

    std::vector<std::vector<int>> D_minus1 = {{-1, 2, 2, 2},
                                               {2, 2, 2, 2},
                                               {2, 2, 2, 2},
                                               {2, 2, 2, 2}};

    std::vector<std::vector<int>> D_plus1 = {{2, 1, 2, 2},
                                              {2, 2, 1, 2},
                                              {2, 2, 2, 1},
                                              {1, 2, 2, 2}};

    MatrixModified graph(4);
    graph.initialize(D_minus1, D_0, D_plus1);

    MatrixModified result = graph.multiply(graph);

    CHECK(result.getElement(0, 0) <= 1.0);
    CHECK(result.getElement(1, 1) == doctest::Approx(0));
    CHECK(result.getElement(2, 2) == doctest::Approx(0));
    CHECK(result.getElement(3, 3) == doctest::Approx(0));
}

TEST_CASE("Matrix:Normalization") {
    std::vector<std::vector<int>> D_0 = {{0, 2, 2, 2},
                                         {2, 0, 2, 2},
                                         {2, 2, 0, 2},
                                         {2, 2, 2, 0}};

    std::vector<std::vector<int>> D_minus1 = {{-1, 2, 2, 2},
                                               {2, 2, 2, 2},
                                               {2, 2, 2, 2},
                                               {2, 2, 2, 2}};

    std::vector<std::vector<int>> D_plus1 = {{2, 1, 2, 2},
                                              {2, 2, 1, 2},
                                              {2, 2, 2, 1},
                                              {1, 2, 2, 2}};

    MatrixModified graph(4);
    graph.initialize(D_minus1, D_0, D_plus1);
    graph.normalize(4);

    CHECK(graph.getElement(0, 0) == -1);
    CHECK(graph.getElement(1, 1) == 0);
    CHECK(graph.getElement(2, 2) == 0);
    CHECK(graph.getElement(3, 3) == 0);
}

TEST_CASE("Matrix:Initialization") {
    std::vector<std::vector<int>> D_0 = {{0, 1},
                                         {1, 0}};
    std::vector<std::vector<int>> D_minus1 = {{-1, 2},
                                               {2, -1}};
    std::vector<std::vector<int>> D_plus1 = {{1, 2},
                                              {2, 1}};
    MatrixModified graph(2);
    graph.initialize(D_minus1, D_0, D_plus1);
    
    CHECK(graph.getElement(0, 0) < 1.0); 
    CHECK(graph.getElement(0, 1) == 0);
    CHECK(graph.getElement(1, 0) == 0);
    CHECK(graph.getElement(1, 1) < 1.0); 
}

TEST_CASE("Identity Matrix") {
    std::vector<std::vector<int>> D_0 = {{0, 1},
                                         {1, 0}};
    std::vector<std::vector<int>> D_minus1 = {{-1, 2},
                                               {2, -1}};
    std::vector<std::vector<int>> D_plus1 = {{1, 2},
                                              {2, 1}};
    MatrixModified graph(2);
    graph.initialize(D_minus1, D_0, D_plus1);

    MatrixModified identity(2);
    identity.initialize({{0, 0},
                         {0, 0}},
                         {{0, 0},
                         {0, 0}},
                         {{1, 0},
                         {0, 1}});

    MatrixModified result = graph.multiply(identity);
    
    CHECK(result.getElement(0, 0) < 1);  
    CHECK(result.getElement(0, 1) == 1);
    CHECK(result.getElement(1, 0) == 1);
    CHECK(result.getElement(1, 1) == 1);
}

TEST_CASE("Zero Matrix") {
    std::vector<std::vector<int>> D_0 = {{0, 0},
                                         {0, 0}};
    std::vector<std::vector<int>> D_minus1 = {{0, 0},
                                               {0, 0}};
    std::vector<std::vector<int>> D_plus1 = {{0, 0},
                                              {0, 0}};
    MatrixModified graph(2);
    graph.initialize(D_minus1, D_0, D_plus1);

    MatrixModified result = graph.multiply(graph);
    CHECK(result.getElement(0, 0) == 2);
    CHECK(result.getElement(0, 1) == 2);
    CHECK(result.getElement(1, 0) == 2);
    CHECK(result.getElement(1, 1) == 2);
}

TEST_CASE("Zero Edge Cost") {
    std::vector<std::vector<int>> D_0 = {{0, 0},
                                         {0, 0}};
    std::vector<std::vector<int>> D_minus1 = {{0, 0},
                                               {0, 0}};
    std::vector<std::vector<int>> D_plus1 = {{0, 0},
                                              {0, 0}};
    MatrixModified graph(2);
    graph.initialize(D_minus1, D_0, D_plus1);
    graph.normalize(2);

    CHECK(graph.getElement(0, 0) == 0);
    CHECK(graph.getElement(0, 1) == 0);
    CHECK(graph.getElement(1, 0) == 0);
    CHECK(graph.getElement(1, 1) == 0);
}

TEST_CASE("Negative Values") {
    std::vector<std::vector<int>> D_0 = {{0, -1},
                                         {-1, 0}};
    std::vector<std::vector<int>> D_minus1 = {{-1, -2},
                                               {-2, -1}};
    std::vector<std::vector<int>> D_plus1 = {{1, 2},
                                              {2, 1}};
    MatrixModified graph(2);
    graph.initialize(D_minus1, D_0, D_plus1);
    
    CHECK(graph.getElement(0, 0) == 9); 
    CHECK(graph.getElement(0, 1) == 0);
    CHECK(graph.getElement(1, 0) == 0);
    CHECK(graph.getElement(1, 1) < 1 );
}


