function divisibleby37() {
    var x = document.getElementById('firstnumber').value
    if ((x % 7 == 0) && (x % 3 == 0))
        var res = "Divisible"
    else
        var res = "Not divisible"
    document.getElementById('result').innerHTML = res
}