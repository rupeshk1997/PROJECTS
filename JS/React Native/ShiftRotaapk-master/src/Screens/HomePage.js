
import React, { useState } from 'react'
import { View, Text, StyleSheet } from 'react-native';
import { NavigationContainer } from '@react-navigation/native';
import { createNativeStackNavigator } from '@react-navigation/native-stack';
import DatePicker from 'react-native-date-picker'
import { Button } from 'react-native-elements';
import Icon from 'react-native-vector-icons/FontAwesome';
import {useEffect} from "react";


const HomePage=()=>{
    const [date, setDate] = useState(new Date())
    const [shift, setShift] = useState({})
    const fetchData = () => {
        return fetch(`http://shiftrotaapi.pythonanywhere.com/${date.getFullYear()}-${date.getMonth()+1}-${date.getDate()}/`)
              .then((response) => response.json())
              .then((data) => setShift(data));}
      
    console.log(date);
    
    fetchData();
    
   
 return(
    <View style={styles.container}>
        <View  style={styles.DateButton}>
        <DatePicker date={date} mode="date" onDateChange={setDate} />
        </View>
        <View style={styles.NonExecutive}>
            <View style={styles.Title}>
            <Text style={styles.TitleText}>Non Executive Shift</Text>
            </View>
            <View style={styles.shift}>
            <View style={styles.shift}>
            <View style={styles.ShiftView}><Text style={styles.ShiftText}>Group A</Text><Text style={styles.ShiftText}>{shift["na"]}</Text></View>
            <View style={styles.ShiftView}><Text style={styles.ShiftText}>Group B</Text><Text style={styles.ShiftText}>{shift["nb"]}</Text></View>
            <View style={styles.ShiftView}><Text style={styles.ShiftText}>Group C</Text><Text style={styles.ShiftText}>{shift["nc"]}</Text></View>
            <View style={styles.ShiftView}><Text style={styles.ShiftText}>Group D</Text><Text style={styles.ShiftText}>{shift["nd"]}</Text></View>
            </View>
            </View>
            
        </View>
        <View style={styles.NonExecutive}>
            <View style={styles.Title}>
            <Text style={styles.TitleText}>Executive Shift</Text>
            </View>
            <View style={styles.shift}>
            <View style={styles.ShiftView}><Text style={styles.ShiftText}>Group A</Text><Text style={styles.ShiftText}>{shift["ea"]}</Text></View>
            <View style={styles.ShiftView}><Text style={styles.ShiftText}>Group B</Text><Text style={styles.ShiftText}>{shift["eb"]}</Text></View>
            <View style={styles.ShiftView}><Text style={styles.ShiftText}>Group C</Text><Text style={styles.ShiftText}>{shift["ec"]}</Text></View>
            <View style={styles.ShiftView}><Text style={styles.ShiftText}>Group D</Text><Text style={styles.ShiftText}>{shift["ed"]}</Text></View>
            </View>
            
        </View>
       
    </View>
 )
}


const styles=StyleSheet.create({
    container:{
        backgroundColor:"#F9F9F9",
        minHeight:'100%',
        display:"flex",
        flex:1,
    },
    DateButton:{
        alignItems:"center",
        backgroundColor:"white",
        width:'100%',
        height:'30%',
        justifyContent:"center",
       
    },
    Button:{
        justifyContent:"center",
        backgroundColor:"white"
    },
    NonExecutive:{
        borderWidth:3,
        margin:10,
        padding:10,
        borderRadius:10,

    },
    TitleText:{
        alignItems:"center",
        color:"#797E95",
        fontSize:25,
        fontFamily:"Roboto-Black",
    },
    Title:{
        alignItems:"center",
    },
    shift:{
        
        margin:10,
    },
    ShiftText:{
        fontFamily:"Roboto-Medium",
        color:"#797E95",
        fontSize :20,
        marginLeft:5,
        marginRight:10,
    },
    ShiftView:{
        display:"flex",
        flexDirection:"row",
    }
})
export default HomePage;