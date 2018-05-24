package com.kodeinc.fireman

import org.apache.commons.io.IOUtils
import java.nio.charset.Charset

object WordList {
    private const val WORDS_LST = "/words.txt"
    private val WORDS_LST_ENCODING = Charset.forName("UTF-8")

    private fun readWordList() : Array<String> {
        val resource = this.javaClass.getResourceAsStream(WORDS_LST)
        val lines = IOUtils.readLines(resource, WORDS_LST_ENCODING)
        return lines.toTypedArray()
    }

    val words by lazy {
        readWordList()
    }

    val reverseOrderedWords by lazy {
        words.sortedArrayWith(Comparator { lhs, rhs ->
            val ll = lhs.length
            val rl = rhs.length
            when {
                ll < rl -> 1
                ll > rl -> -1
                else -> 0
            }
        })
    }
}

typealias Bucket = List<String>

internal typealias MutableBucket = ArrayList<String>

internal fun MutableBucket.lengthOrder() = this.sortWith(Comparator { lhs, rhs ->
    val ll = lhs.length
    val rl = rhs.length
    when {
        ll < rl -> -1
        ll > rl -> 1
        else -> 0
    }
})


abstract class BucketCollection<K : Comparable<K>> {
    protected val buckets : MutableMap<K, MutableBucket> = HashMap()

    abstract fun transformToKey(word : String) : K

    operator fun get(key : K) : Bucket? = buckets[key]

    fun getByWord(word : String) = get(transformToKey(word))

    operator fun contains(key: K) : Boolean = key in buckets

    operator fun plus(word : String) {
        val key = transformToKey(word)

        if (key !in buckets) {
            buckets[key] = ArrayList()
        }

        buckets[key]?.add(word)
    }

    fun add(word : String) = this + word

    fun sortBuckets() = buckets.forEach { _, value -> value.lengthOrder() }

    open operator fun iterator() : Iterator<Bucket> {
        return object : Iterator<Bucket> {
            val itr = buckets.iterator()

            override fun hasNext() = itr.hasNext()

            override fun next(): Bucket {
                val e = itr.next()
                return e.value
            }

        }
    }
}

class TwoLetterBuckets : BucketCollection<String>() {
    override fun transformToKey(word: String): String = if (word.length <= 2) {
        word
    } else {
        word.substring(0, 2)
    }
}

class LengthBuckets : BucketCollection<Int>() {
    override fun transformToKey(word: String): Int = word.length

    private val keyList by lazy {
        buckets.keys.toSortedSet().reversed()
    }

    override operator fun iterator(): Iterator<Bucket> {
        return object : Iterator<Bucket> {
            private var index = 0

            override fun hasNext() = index < keyList.size

            override fun next() = if (hasNext()) {
                val key = keyList[index++]
                buckets[key] ?: emptyList<String>()
            } else {
                throw NoSuchElementException()
            }
        }
    }
}
