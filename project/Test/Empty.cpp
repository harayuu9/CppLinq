﻿#include "Test.h"

TEST( Empty, Normal )
{
    const auto empty = linq::Empty<int>() << linq::ToVector();

    const std::vector<int> vec;

    ASSERT_EQ( empty, vec );
}

#if ENABLE_PERF
static void NativeEmpty( benchmark::State& state )
{
    while ( state.KeepRunning() )
    {
        MEM_RESET();
        const std::vector<int> vec;
        MEM_COUNTER( state );
    }
}

static void LinqForCppEmpty( benchmark::State& state )
{
    while ( state.KeepRunning() )
    {
        MEM_RESET();
        const auto empty = linq::Empty<int>() << linq::ToVector();
        MEM_COUNTER( state );
    }
}

static void CppLinqEmpty( benchmark::State& state )
{
    while ( state.KeepRunning() )
    {
        MEM_RESET();
        const auto empty = cpplinq::empty<int>() >> cpplinq::to_vector();
        MEM_COUNTER( state );
    }
}

BENCHMARK( NativeEmpty );
BENCHMARK( LinqForCppEmpty );
BENCHMARK( CppLinqEmpty );
#endif
