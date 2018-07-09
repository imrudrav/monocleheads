//
//  ViewController.swift
//  FenceGUI_v5
//
//  Created by Tanner Orndorff on 7/7/18.
//  Copyright © 2018 Monocle Heads. All rights reserved.
//

import UIKit

class ViewController: UITableViewController {

    let array = ["item1","item2","item3"]
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        //create a business or load an existing one
        
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return array.count
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "customcell")
        cell?.textLabel?.text = array[indexPath.item]
        return cell!
    }
}

