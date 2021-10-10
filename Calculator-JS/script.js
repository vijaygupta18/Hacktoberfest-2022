var result = "";
$('#plus').on('click', function () {
    $(".screen").append("+");
    result += "+";
});
$('#minus').on('click', function () {
    $(".screen").append("-");
    result += "-";
});
$('#multiply').on('click', function () {
    $(".screen").append("x");
    result += "*";
});
$('#divide').on('click', function () {
    $(".screen").append("÷");
    result += "/";
});
$('#C').on('click', function () {
    $(".screen").text("");
    result = "";
});
$('#seven').on('click', function () {
    $(".screen").append("7");

    result += "7";
});
$('#eight').on('click', function () {
    $(".screen").append("8");

    result += "8";
});
$('#nine').on('click', function () {
    $(".screen").append("9");

    result += 9;
});
$('#four').on('click', function () {
    $(".screen").append("4");

    result += 4;
});
$('#five').on('click', function () {
    $(".screen").append("5");

    result += 5;
});
$('#six').on('click', function () {
    $(".screen").append("6");

    result += 6;
});
$('#one').on('click', function () {
    $(".screen").append("1");

    result += 1;
});
$('#two').on('click', function () {
    $(".screen").append("2");

    result += 2;
});
$('#three').on('click', function () {
    $(".screen").append("3");

    result += 3;
});
$('#zero').on('click', function () {
    $(".screen").append("0");

    result += 0;
});
$('#dot').on('click', function () {
    $(".screen").append(".");
    result += ".";
});

//code for expression
$('#equal').on('click', function () {

    result = eval(result);
    $(".screen").text(result);

});
