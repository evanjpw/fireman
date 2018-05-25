package com.kodeinc.fireman


fun main(args: Array<String>) {
    println("Working")

    val solver = Solver()

    // solver.printBuckets()

    val (bestDepth, _) = solver.solve()  //bestLength

    if (!bestDepth.isEmpty) {
        println("Found word with greatest number of sub-words: \"${bestDepth.word}\", with a count of ${bestDepth.depth} sub-words.")
    } else {
        println("No word found that meets the criteria.")
    }

//    if (!bestLength.isEmpty) {
//        println("Found best length word ${bestLength.word}, with deptth of ${bestLength.depth}")
//    } else {
//        println("No best length word found")
//    }

    println("Done")
}
