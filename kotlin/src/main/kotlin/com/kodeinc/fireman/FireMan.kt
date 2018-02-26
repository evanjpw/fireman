package com.kodeinc.fireman

data class WordDepthPair(val word: String?, val depth : Int) : Comparable<WordDepthPair> {

    constructor() : this(null, 0)

    val length get() = word?.length ?: 0

    val isEmpty get() = (word == null || word.isEmpty()) && depth == 0

    override fun equals(other: Any?) : Boolean {
        return when (other) {
            null -> false
            is WordDepthPair -> this.depth == other.depth
            else -> false
        }
    }

    override operator fun compareTo(other: WordDepthPair) : Int {
        return when {
            this.depth < other.depth -> -1
            this.depth > other.depth -> 1
            else -> 0
        }
    }

    override fun hashCode(): Int {
        return depth
    }
}



class Solver {
    private val EMPTY_WORD_DEPTH_PAIR = WordDepthPair()
    private val tlBuckets : TwoLetterBuckets = TwoLetterBuckets()

    init {
        WordList.words.forEach { word -> tlBuckets.add(word) }

        tlBuckets.sortBuckets()
    }

    fun printBuckets() {
        for (bucket in tlBuckets) {
            println("-------")
            for (word in bucket) {
                println("     $word")
            }
        }
    }

    fun solve() : Pair<WordDepthPair, WordDepthPair> {
        var bestLength : WordDepthPair = EMPTY_WORD_DEPTH_PAIR
        var bestDepth : WordDepthPair = EMPTY_WORD_DEPTH_PAIR
        for (word in WordList.reverseOrderedWords) {
            val depth = tryWord(word)
            if (depth > bestDepth.depth) {
                bestDepth = WordDepthPair(word, depth)
            }
            if (word.length > bestLength.length) {
                bestLength = WordDepthPair(word, depth)
            }
        }
        return Pair(bestDepth, bestLength)
    }

    private fun tryWord(word: String, depth : Int = 0) : Int {
        val bucket = tlBuckets.getByWord(word)
        bucket?.takeWhile { it.length <= word.length }?.forEach {
            if (word == it) {
                return depth + 1
            } else if (word.startsWith(it, ignoreCase = true)) {
                val nDepth = tryWord(word.substring(it.length))
                if (nDepth != 0) {
                    return nDepth
                }
            }
        }
        return 0
    }
}

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
