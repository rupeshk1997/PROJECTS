const express = require('express')
const bodyParser = require('body-parser')
const dotenv = require('dotenv');
dotenv.config();
const nodemailer = require("nodemailer");

const app = express()


app.use(bodyParser.urlencoded({ extended: false }))
var cors = require('cors')
app.use(cors())
app.use(bodyParser.json())



app.post('/', async (req, res) => {
    const {email,message,subject,name} = req.body;
    console.log(process.env.EMAIL)
    let transporter = nodemailer.createTransport({
        host: "smtp.gmail.com",
        port: 465,
        secure: true, 
        auth: {
            user: process.env.EMAIL, 
            pass: process.env.PASSWORD, 
        },
    });
    
    const msg = {
        from:  ` ${name}`,
        to: process.env.EMAIL2,
        subject: `Complaint from ${name}`, 
        text: `Name->${name}\nEmail-->${email}\nComplaint-->${message}`
    }
    const info = await transporter.sendMail(msg).catch(error=>console.log(error));
    res.send('Email Sent!')
})

app.listen(process.env.PORT || 3000, () => console.log("Server is running..."));