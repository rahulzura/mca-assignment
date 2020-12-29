const onSubmitHandler = (e) => {
    const nameEl = document.querySelector("name-input");
    const emailEl = document.querySelector("email-input");
    const phoneEl = document.querySelector("phone-input");
    const qualificationEl = document.querySelector("qualification-input");
    const programEl = document.querySelector("program-input");

    console.log(nameEl.value, emailEl.value, phoneEl.value, qualificationEl.value, programEl.value);
}