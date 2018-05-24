package com.kodeinc.fireman


fun main(args: Array<String>) {
    println("Working")

    val solver = Solver()

    // solver.printBuckets()

    val (bestDepth, bestLength) = solver.solve()

    if (!bestDepth.isEmpty) {
        println("Found word with best depth ${bestDepth.word}, with depth of ${bestDepth.depth}")
    } else {
        println("No best depth word found")
    }

    if (!bestLength.isEmpty) {
        println("Found best length word ${bestLength.word}, with deptth of ${bestLength.depth}")
    } else {
        println("No best length word found")
    }

    println("Done")
}
