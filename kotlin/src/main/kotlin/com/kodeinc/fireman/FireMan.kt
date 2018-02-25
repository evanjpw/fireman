package com.kodeinc.fireman

fun main(args: Array<String>) {
    println("Working")

    val tlBuckets = TwoLetterBuckets()

    WordList.words.forEach { word -> tlBuckets.add(word) }

    tlBuckets.sortBuckets()

    for (bucket in tlBuckets) {
        println("-------")
        for (word in bucket) {
            println("     $word")
        }
    }

    for(word in WordList.reverseOrderedWords) {

    }

    println("Done")
}
