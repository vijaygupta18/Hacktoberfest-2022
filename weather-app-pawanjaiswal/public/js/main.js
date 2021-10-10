const cityName = document.getElementById('cityName')
const weathercard = document.getElementById('weathercard')
const submitBtn = document.getElementById('submitBtn')


const city = document.getElementById('city')
const temperature = document.getElementById('temperature')
const feels_like = document.getElementById('feels_like')
const humidity = document.getElementById('humidity')
const temp_status = document.getElementById('temp_status')

const getInfo = async(event) => {
    event.preventDefault();
    
    let cityval = cityName.value;

    if(cityval === ""){
        weathercard.hidden
    }
    else{
       try {
            let url = `http://api.openweathermap.org/data/2.5/weather?q=${cityval}&appid=fbf8f4a8aabcd965e5d5b8713b17fb1e`
            const response = await fetch(url);
            const data = await response.json();
            const arrdata = [data];

            dtemp = arrdata[0].main.temp - 273.15;
            original_temp = Math.floor(dtemp);

            dfeels_like = arrdata[0].main.feels_like - 273.15;
            original_feels_like = Math.floor(dfeels_like)

            city.innerHTML = arrdata[0].name;
            temperature.innerHTML = `${original_temp}°`;
            feels_like.innerHTML = `${original_feels_like}°`;
            humidity.innerHTML = `${arrdata[0].main.humidity}`;
            

            temp_status.innerHTML = `${arrdata[0].weather[0].main}<span>Wind ${arrdata[0].wind.speed}km/h</span> `;
            console.log(arrdata);
       } catch (error) {
           
       }
       

    }
}

submitBtn.addEventListener('click',getInfo);